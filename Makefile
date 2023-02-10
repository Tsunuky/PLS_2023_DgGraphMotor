MOD		=	`pwd | rev | cut -d "/" -f3 | rev`

BIN		=	`pwd | rev | cut -d "/" -f1 | rev`
OUTPUT 	= libprout.so
FLAG		=	-W -Wall -Wextra -g3

INCLUDE	=	-I./include/ -I./submodule/spdlog/include/spdlog
SRC		=	$(wildcard src/*.cpp)
OBJ		=	$(SRC:.cpp=.o)
LIB		=	-lstdc++ -lm -ldl -lgcc_s -lavcall -O0 -g3 -ggdb3 -lglut -lGL -lGLU -lGLEW #-lglfw
LIB		+=  -L./submodule/spdlog/build/ -lspdlog
all:		bin

bin:		$(OBJ)
		@printf "[\033[0;33m====\033[0m]% 72s\r" $(BIN) | tr " " "."
		@g++ $(OBJ) -o $(BIN) $(LIBPATH) $(LIB)
		@printf "[\033[0;32m====\033[0m]% 72s\n" $(BIN) | tr " " "."

sub:
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."
		mkdir -p submodule/spdlog/build
		cmake -S submodule/spdlog -B submodule/spdlog/build
		make -C submodule/spdlog/build -j
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."

subclean:
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."
		make -C submodule/spdlog/build -j clean
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."

subfclean:
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."
		rm -rf submodule/spdlog/build
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."

.cpp.o:
		@printf "[\033[;33m====\033[0m]% 72s\r" $< | tr " " "."
		@g++ $(INCLUDE) $(FLAG) -c $< -o $@
		@printf "[\033[0;32m====\033[0m]% 72s\n" $< | tr " " "."

clean:
		@printf "[\033[0;33m####\033[0m]% 72s\r" $(OBJS) | tr " " "."
		@rm -f $(OBJ)
		@printf "[\033[0;31m####\033[0m]% 72s\n" $(OBJS) | tr " " "."

fclean:	clean
		@printf "[\033[0;33m####\033[0m]% 72s\r" $(BIN) | tr " " "."
		@rm -f $(BIN)
		@printf "[\033[0;31m####\033[0m]% 72s\n" $(BIN) | tr " " "."

re:		fclean all

lib:    $(OBJ)
		@g++ -shared  -fprofile-arcs -o $(OUTPUT) $(OBJ) $(LIB) 

.PHONY: all clean fclean re

.SUFFIXES: .cpp .o
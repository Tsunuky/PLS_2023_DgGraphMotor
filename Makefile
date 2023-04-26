MOD			=	`pwd | rev | cut -d "/" -f3 | rev`

BIN			=	`pwd | rev | cut -d "/" -f1 | rev`

FLAG		=	-std=c++20 -W -Wall -Wextra -g3

INCLUDE		=	-I./include/ 
INCLUDE	   +=   -I./include/event/
INCLUDE	   +=   -I./include/imGui/
#INCLUDE	   +=   -I./include/precompile/
INCLUDE	   +=   -I./submodule/spdlog/include/
INCLUDE	   +=	-I./submodule/imgui/

LIB			=	-lstdc++ -lfmt -lm -ldl -lgcc_s -lavcall -O0 -g3 -ggdb3 -lglut -lGL -lGLU -lGLEW -limGui #-lglfw
LIB		   += 	-L./submodule/spdlog/build/ -L./submodule/imgui/

PCH_DIR		=	./include/precompile
PCH_FLAG	=	-std=c++20 -O2
PCH_SRC 	=	$(PCH_DIR)/precompile.hpp
#PCH_HEADER	=

SRC			=	$(wildcard src/*.cpp) \
				$(wildcard src/imGui/*.cpp)
OBJ			=	$(SRC:.cpp=.o)

#all:		precompile bin
all:		bin

bin:		$(OBJ)
		@printf "[\033[0;33m====\033[0m]% 72s\r" $(BIN) | tr " " "."
		@g++ $(OBJ) -o $(BIN) $(LIBPATH) $(LIB)
		@printf "[\033[0;32m====\033[0m]% 72s\n" $(BIN) | tr " " "."

suball: sub_spdlog sub_imgui

sub_spdlog:
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."
		mkdir -p submodule/spdlog/build
		cmake -S submodule/spdlog -B submodule/spdlog/build
		make -C submodule/spdlog/build -j
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."

sub_imgui: $(IMGUI_OBJS)
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."
		make -C submodule/imgui -j
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."

subclean:
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."
		make -C submodule/spdlog/build -j clean
		make -C submodule/imgui/ -j clean
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."

subfclean:
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."
		rm -rf submodule/spdlog/build
		make -C submodule/imgui/ -j fclean
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."

precompile:
		@printf "[\033[;33m====\033[0m]% 72s\r" "precompile header" | tr " " "."
		@g++ $(PCH_FLAG) $(PCH_SRC)
		@printf "[\033[0;32m====\033[0m]% 72s\n" "precompile header" | tr " " "."

.cpp.o:
		@printf "[\033[;33m====\033[0m]% 72s\r" $< | tr " " "."
		@g++ $(FLAG) $(INCLUDE) -c $<  -o $@
		@printf "[\033[0;32m====\033[0m]% 72s\n" $< | tr " " "."

clean:
		@printf "[\033[0;33m####\033[0m]% 72s\r" $(OBJS) | tr " " "."
		@rm -f $(OBJ)
		@printf "[\033[0;31m####\033[0m]% 72s\n" $(OBJS) | tr " " "."

fclean:		clean
		@printf "[\033[0;33m####\033[0m]% 72s\r" $(BIN) | tr " " "."
		@rm -f $(BIN)
		@printf "[\033[0;31m####\033[0m]% 72s\n" $(BIN) | tr " " "."
		@printf "[\033[0;33m####\033[0m]% 72s\r" "precompiled header" | tr " " "."
		@rm -f ./include/precompile.hpp.gch
		@printf "[\033[0;31m####\033[0m]% 72s\n" "precompiled header" | tr " " "."

re:			fclean all

lib:		$(OBJ)
		@g++ -shared  -fprofile-arcs -o $(OUTPUT) $(OBJ) $(LIB) 

.PHONY:		all clean fclean re

.SUFFIXES: .cpp .o .gch
###
#imgui make a deplacer plus tard

IMGUI_DIR	=	./imgui/

IMGUI_FILE	=	$(wildcard $(IMGUI_DIR)/*.cpp)

CXXFLAGS	=	-std=c++11 -I$(IMGUI_DIR)
CXXFLAGS	+=	-g -Wall -Wformat

LIBS		+= -lGL `pkg-config --static --libs glfw3`

CXXFLAGS	+= `pkg-config --cflags glfw3`

IMGUI_OBJS = $(addsuffix .o, $(basename $(notdir $(IMGUI_FILE))))

%.o:$(IMGUI_DIR)/%.cpp
	@g++ $(CXXFLAGS) -c -o $@ $<
###

#all:		precompile bin
all:		bin

bin: $(IMGUI_OBJS)
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."
		@ar -rc libimGui.a $(IMGUI_OBJS) 
		@printf "[\033[0;33m====\033[0m]% 72s\r" | tr " " "."
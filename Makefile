NAME = scop
CC = clang


all: $(NAME)

FILES = $(shell find . -name \*.cpp)

$(NAME):
	$(CC) -g3 -fsanitize=address -fno-omit-frame-pointer --std=c++17 -lstdc++ -o $(NAME) $(FILES) -Iinclude/ -Iglew-2.1.0/include/ -lSDL2 -Wl,-\( -lm -lpthread -L./glew-2.1.0/lib -lGLEW -lGL -ldl -Wl,-\)

clean:
	rm -rf $(NAME)

.PHONY: $(NAME)
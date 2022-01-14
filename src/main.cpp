#include <iostream>
#include <Vector3.hpp>
#include <Vector2.hpp>
#include <cxxabi.h>
#include <csignal>
#include "ShaderProgram.hpp"
#include "WindowManager.hpp"

extern "C" {
	#include "GL/glew.h"
	#include <SDL2/SDL.h>
};

int main(int ac, char **av)
{
	Scop::WindowManager windowManager;

	std::cout << SDL_Init(SDL_INIT_VIDEO) << std::endl;
	Scop::Window window("Main window", Vector2i(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED), Vector2i(1280, 720), SDL_WINDOW_SHOWN);
//
	Scop::Window& win = windowManager.AddWindow(std::move(window));
//	if (glewInit() != GLEW_OK) {
//		std::cout << "Fail to init glew" << std::endl;
//		exit(EXIT_FAILURE);
//	}
//	Scop::ShaderProgram program;
//	SDL_Window* win = SDL_CreateWindow("Main", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	std::cout << SDL_GetError() << std::endl;
	SDL_Event e;
	bool quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			if (e.type == SDL_KEYDOWN)
			{
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				quit = true;
			}
		}
		SDL_UpdateWindowSurface(win.GetWindowHandle());
	}
//	SDL_UpdateWindowSurface(win);
	SDL_Delay(2000);
	return 1;
}

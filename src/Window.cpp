//
// Created by killian on 08/01/2022.
//

#include <utility>
#include "Window.hpp"

Scop::Window::Window(const std::string& title, const Vector2i& pos, const Vector2i& size, u_int32_t flags)
{
	handle = SDL_CreateWindow(title.c_str(), pos.x, pos.y, size.x, size.y, flags);
	if (handle == nullptr)
		throw std::runtime_error("Fail to create window (" + title + ")");
	std::cout << handle << std::endl;
	SDL_GetWindowPosition(handle, &position.x, &position.y);
}

Scop::Window::~Window()
{
	std::cout << "DestroyWindow" << std::endl;
	if (handle != nullptr)
	{
		SDL_DestroyWindow(handle);
	}
}

int Scop::Window::HandleEvent(void *userData, SDL_Event *event)
{
	Window* window = static_cast<Window*>(userData);

//	if (SDL_GetWindowID())
	return 0;
}

u_int32_t Scop::Window::GetId()
{
	return SDL_GetWindowID(handle);
}

SDL_Window *Scop::Window::GetWindowHandle()
{
	return handle;
}

Vector2i Scop::Window::GetPosition() const
{
	return position;
}

Scop::Window::Window(Scop::Window&& window) noexcept:
	handle(std::exchange(window.handle, nullptr)),
	position(window.position),
	size(window.size)
{
}

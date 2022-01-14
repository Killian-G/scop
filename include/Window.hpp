//
// Created by killian on 08/01/2022.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <string>
#include "Vector2.hpp"

namespace Scop
{

	class Window
	{
	public:
		Window(Window&& window) noexcept;
		Window(const std::string& title, const Vector2i& pos, const Vector2i& size, u_int32_t flags);
		~Window();
		[[nodiscard]] u_int32_t GetId();
		[[nodiscard]] SDL_Window* GetWindowHandle();
		[[nodiscard]] Vector2i GetSize() const;
		[[nodiscard]] Vector2i GetPosition() const;
		[[nodiscard]] std::string GetTitle() const;


	private:
		static int SDLCALL HandleEvent(void *userData, SDL_Event* event);
		SDL_Window *handle;
		Vector2i position;
		Vector2i size;
	};
}


#endif //WINDOW_HPP

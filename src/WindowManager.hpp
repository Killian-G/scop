//
// Created by killian on 08/01/2022.
//

#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <unordered_map>
#include <vector>
#include "Window.hpp"

namespace Scop
{
	class WindowManager
	{
	public:
		Window& AddWindow(Window&& window);
		WindowManager& GetInstance() { return}

	private:
		static WindowManager&
		std::unordered_map<u_int32_t, Window> windows;
	};
}


#endif //WINDOWMANAGER_HPP

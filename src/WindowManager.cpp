//
// Created by killian on 08/01/2022.
//

#include "WindowManager.hpp"

namespace Scop {
	Window& WindowManager::AddWindow(Window&& window)
	{
		uint32_t index = window.GetId();
		auto test = windows.emplace(index, std::move(window));
		return test.first->second;
	}
}

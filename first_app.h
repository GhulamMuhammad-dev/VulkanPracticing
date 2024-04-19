#pragma once

#include "lve_window.h"

namespace lve {
	class FirstApp {
	private:
		LveWindow lveWindow{WIDTH,HEIGHT,"Hello vulkan"};
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;
		void run();

	 };
}
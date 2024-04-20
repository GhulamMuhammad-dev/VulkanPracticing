#pragma once

#include "lve_window.h"
#include "lve_pipeline.h"

namespace lve {
	class FirstApp {
	private:
		LveWindow lveWindow{WIDTH,HEIGHT,"Hello vulkan"};
		LvePipeline LvePipeline{ "simple_shader.vert.spv","simple_shader.frag.spv" };
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;
		void run();

	 };
}
#pragma once

#include "lve_window.h"
#include "lve_pipeline.h"
#include "lve_device.hpp"

namespace lve {
	class FirstApp {
	private:
		LveWindow lveWindow{WIDTH,HEIGHT,"Hello vulkan"};
		LveDevice lveDevice{ lveWindow };
		LvePipeline LvePipeline{lveDevice, "simple_shader.vert.spv","simple_shader.frag.spv",LvePipeline::defaulPipeLineConfigInfo(WIDTH,HEIGHT)};
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;
		void run();

	 };
}
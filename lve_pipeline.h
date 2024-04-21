#pragma once
using namespace std;
#include "lve_device.hpp"
#include<string>
#include<vector>
namespace lve {
	struct PipeLineConfigInfo {

	};
	class LvePipeline {
	private:
		static vector<char> readFile(const string& filePath);
		void createGraphicsPipeline(const string& vertFilePath, const string& fragFilePath, const PipeLineConfigInfo& configInfo);
		void createShaderModule(const vector<char>& code, VkShaderModule* shaderModule);
		LveDevice& lveDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;

	public:
		LvePipeline( LveDevice& device,  const string& vertFilePath, const string& fragFilePath,const PipeLineConfigInfo & configInfo);

		~LvePipeline() {};
		LvePipeline(const LvePipeline&) = delete;
		void operator=(const LvePipeline&) = delete;

		static PipeLineConfigInfo defaulPipeLineConfigInfo(uint32_t width, uint32_t height);
	};
}

#include "lve_pipeline.h"
#include<fstream>
#include<stdexcept>
#include<iostream>
using namespace std;

namespace lve {
	LvePipeline::LvePipeline(LveDevice& device, const string& vertFilePath, const string& fragFilePath, const PipelineConfigInfo& configInfo) :lveDevice{device} {
		createGraphicsPipeline(vertFilePath, fragFilePath,configInfo);
	};
	vector<char> LvePipeline::readFile(const string& filePath) {
	
		ifstream file{ filePath,ios::ate | ios::binary };
		if (!file.is_open()) {
			throw runtime_error("failed to open file:" + filePath);

		}
		size_t fileSize = static_cast<size_t>(file.tellg());
		vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);
		file.close();
		return buffer;



	
	}

	void LvePipeline::createGraphicsPipeline(const string& vertFilePath, const string& fragFilePath, const PipelineConfigInfo& configInfo) {
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);

		cout << "Vertex shader code size" << vertCode.size() << endl;
		cout << "fragment shader code size" << fragCode.size() << endl;
	};

	void LvePipeline::createShaderModule(const vector<char>& code, VkShaderModule* shaderModule) {
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
			throw runtime_error("failed to create shader module");
		}
	
	}

      PipelineConfigInfo LvePipeline::defaulPipeLineConfigInfo(uint32_t width, uint32_t height) {
		  PipelineConfigInfo configInfo{};
		  configInfo.inputAssemblyInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		  configInfo.inputAssemblyInfo.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		  configInfo.inputAssemblyInfo.primitiveRestartEnable = VK_FALSE;

		  configInfo.viewport.x = 0.0f;
		  configInfo.viewport.y = 0.0f;
		  configInfo.viewport.width = static_cast<float>(width);
		  configInfo.viewport.height = static_cast<float>(height);
		  configInfo.viewport.minDepth = 0.0f;
		  configInfo.viewport.maxDepth = 1.0f;

		  configInfo.scissor.offset = { 0, 0 };
		  configInfo.scissor.extent = { width, height };

		  return configInfo;
	 }


}
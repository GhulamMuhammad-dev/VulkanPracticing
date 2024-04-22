#pragma once
using namespace std;
#include "lve_device.hpp"
#include<string>
#include<vector>
namespace lve {
	struct PipelineConfigInfo {
		VkViewport viewport;
		VkRect2D scissor;
		VkPipelineViewportStateCreateInfo viewportInfo;
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};
	class LvePipeline {
	private:
		static vector<char> readFile(const string& filePath);
		void createGraphicsPipeline(const string& vertFilePath, const string& fragFilePath, const PipelineConfigInfo& configInfo);
		void createShaderModule(const vector<char>& code, VkShaderModule* shaderModule);
		LveDevice& lveDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;

	public:
		LvePipeline( LveDevice& device,  const string& vertFilePath, const string& fragFilePath,const PipelineConfigInfo & configInfo);

		~LvePipeline() {};
		LvePipeline(const LvePipeline&) = delete;
		void operator=(const LvePipeline&) = delete;

		static PipelineConfigInfo defaulPipeLineConfigInfo(uint32_t width, uint32_t height);
	};
}

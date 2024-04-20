#pragma once
using namespace std;
#include<string>
#include<vector>
namespace lve {
	class LvePipeline {
	private:
		static vector<char> readFile(const string& filePath);
		void createGraphicsPipeline(const string& vertFilePath, const string& fragFilePath);
	public:
		LvePipeline(const string& vertFilePath, const string& fragFilePath);
	};
}

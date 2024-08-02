
#include "Fjordimm3DEngine/(FileLoading)/FileLoading.hpp"

#include <iostream>
#include <fstream>
#include "CMakeConfig.h"
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine::FileLoading
{
	std::unique_ptr<const std::string> LoadFileAsText(const std::string name)
	{
		std::string fullName = std::string(CMAKECONFIG_SOURCE_DIR) + "/libs/Fjordimm3DEngine/" + name;

		FILE* file = fopen(fullName.c_str(), "r");

		if (!file)
		{
			Debug::LogNonfatalError("Couldn't open file, returned nullptr.");
			return nullptr;
		}

		fseek(file, 0, SEEK_END);
		size_t size = ftell(file);
		fseek(file, 0, SEEK_SET);

		char* buf = new char[size + 1];

		size_t charsRead = fread(buf, sizeof(char), size, file);
		buf[charsRead] = '\0';

		fclose(file);

		std::unique_ptr<const std::string> ret(new const std::string(buf));
		return std::move(ret);
	}
}

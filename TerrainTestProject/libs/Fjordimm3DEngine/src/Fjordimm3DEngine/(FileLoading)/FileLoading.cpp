
#include "Fjordimm3DEngine/(FileLoading)/FileLoading.hpp"

#include <iostream>
#include <fstream>
#include "lodepng.h"
#include "CMakeConfig.h"
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine::FileLoading
{
	std::unique_ptr<std::string const> LoadFileAsText(std::string const& name)
	{
		std::string fullName = std::string(CMAKECONFIG_SOURCE_DIR) + "/libs/Fjordimm3DEngine/" + name;

		FILE* file = std::fopen(fullName.c_str(), "r");

		if (!file)
		{
			Debug::LogNonfatalError("Couldn't open file, returning nullptr.");
			return nullptr;
		}

		std::fseek(file, 0, SEEK_END);
		size_t size = std::ftell(file);
		std::fseek(file, 0, SEEK_SET);

		char* buf = new char[size + 1];
		FJORDIMM3DENGINE_DEBUG_ASSERT(buf != nullptr);

		size_t charsRead = std::fread(buf, sizeof(char), size, file);
		buf[charsRead] = '\0';

		std::fclose(file);

		std::unique_ptr<std::string const> ret(new std::string const(buf));
		return ret;
	}
	
	std::unique_ptr<std::vector<unsigned char>> LoadImage(std::string const& name, std::size_t& imageWidth, std::size_t& imageHeight)
	{
		std::string fullName = std::string(CMAKECONFIG_SOURCE_DIR) + "/libs/Fjordimm3DEngine/" + name;

		std::vector<unsigned char> buf;
		unsigned int width;
		unsigned int height;

		unsigned int lodepngError = lodepng::decode(buf, width, height, fullName.c_str());
		if (lodepngError)
		{
			Debug::LogNonfatalError("Couldn't open image, returning nullptr.");
			imageWidth = 0;
			imageHeight = 0;
			return nullptr;
		}
		else
		{
			imageWidth = width;
			imageHeight = height;
			
			std::unique_ptr<std::vector<unsigned char>> ret = std::make_unique<std::vector<unsigned char>>();
			ret->resize(4 * imageWidth * imageHeight);
			for (std::size_t r = 0; r < imageHeight; r++)
			{
				for (std::size_t c = 0; c < imageWidth; c++)
				{
					std::size_t rP = imageHeight - 1 - r;

					ret->at(4 * (r * imageWidth + c) + 0) = buf[4 * (rP * imageWidth + c) + 0];
					ret->at(4 * (r * imageWidth + c) + 1) = buf[4 * (rP * imageWidth + c) + 1];
					ret->at(4 * (r * imageWidth + c) + 2) = buf[4 * (rP * imageWidth + c) + 2];
					ret->at(4 * (r * imageWidth + c) + 3) = buf[4 * (rP * imageWidth + c) + 3];
				}
			}

			return ret;
		}
	}
}

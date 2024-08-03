
#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Fjordimm3DEngine::FileLoading
{
	std::unique_ptr<const std::string> LoadFileAsText(const std::string name);
	std::unique_ptr<std::vector<unsigned char>> LoadImage(const std::string name, std::size_t& imageWidth, std::size_t& imageHeight);
}

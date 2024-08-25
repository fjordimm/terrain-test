
#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Fjordimm3DEngine::FileLoading
{
	std::unique_ptr<std::string const> LoadFileAsText(std::string const& name);
	std::unique_ptr<std::vector<unsigned char>> LoadImage(std::string const& name, std::size_t& imageWidth, std::size_t& imageHeight);
}

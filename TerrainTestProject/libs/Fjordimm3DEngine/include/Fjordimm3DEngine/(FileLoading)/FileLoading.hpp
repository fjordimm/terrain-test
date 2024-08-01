
#pragma once

#include <memory>
#include <string>

namespace Fjordimm3DEngine::FileLoading
{
	std::unique_ptr<const std::string> LoadFile(const std::string name);
}

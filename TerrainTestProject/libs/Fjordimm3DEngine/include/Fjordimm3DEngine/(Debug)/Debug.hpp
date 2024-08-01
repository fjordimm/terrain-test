
#pragma once

#include <mutex>

namespace Fjordimm3DEngine::Debug
{
	namespace _Globals
	{
		static std::mutex _GlobalMutex_debug;
	}
}

#include "Fjordimm3DEngine/(Debug)/_logging.hpp"

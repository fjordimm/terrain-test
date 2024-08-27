
#pragma once

#include "CMakeConfig.h"

namespace Fjordimm3DEngine::Debug
{
	void Printf(char const* const format, ...);
	void Log(char const* const format, ...);
	void LogWarning(char const* const format, ...);
	void LogNonfatalError(char const* const format, ...);
	void LogFatalError(char const* const format, ...);
	void Exit();

	void __Assert(bool expr, int lineNum, char const* filename);
	#ifdef CMAKECONFIG_DO_ASSERTIONS
		#define FJORDIMM3DENGINE_DEBUG_ASSERT(EXPR) Fjordimm3DEngine::Debug::__Assert(EXPR, __LINE__, __FILE__)
	#else
		#define FJORDIMM3DENGINE_DEBUG_ASSERT(EXPR) Fjordimm3DEngine::Debug::Log("howeiieieie")
	#endif

	void CheckOpenGLErrors();
}

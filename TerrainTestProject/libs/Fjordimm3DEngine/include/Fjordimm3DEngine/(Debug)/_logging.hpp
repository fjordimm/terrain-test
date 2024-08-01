
#pragma once

#include "CMakeConfig.h"

namespace Fjordimm3DEngine::Debug
{
	void Log(const char* msg);
	void LogWarning(const char* msg);
	void LogNonfatalError(const char* msg);
	void LogFatalError(const char* msg);
	void Printf(char const* const format, ...);
	void Logf(char const* const format, ...);
	void Exit();

	void _Assert(bool expr);
	#ifdef CMAKECONFIG_DO_ASSERTIONS
		#define FJORDIMM3DENGINE_DEBUG_ASSERT(Expr) Fjordimm3DEngine::Debug::_Assert(Expr)
	#else
		#define FJORDIMM3DENGINE_DEBUG_ASSERT(Expr) Fjordimm3DEngine::Debug::Log("howeiieieie")
	#endif
}


#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
// #include "Fjordimm3DEngine/(Debug)/_logging.hpp"

#include <cstdio>
#include <cstdarg>
#include <cstdlib>

#ifdef CMAKECONFIG_DO_TERMINAL_COLORS
static constexpr char PRINTCOLOR_DEBUG[] = "\033[32m"; // green
static constexpr char PRINTCOLOR_WARNING[] = "\033[33m"; // yellow
static constexpr char PRINTCOLOR_ERROR[] = "\033[31m"; // red
static constexpr char PRINTCOLOR_NONE[] = "\033[0m";
#else
static constexpr char PRINTCOLOR_DEBUG[] = "";
static constexpr char PRINTCOLOR_WARNING[] = "";
static constexpr char PRINTCOLOR_ERROR[] = "";
static constexpr char PRINTCOLOR_NONE[] = "";
#endif

namespace Fjordimm3DEngine::Debug
{
	void Log(char const* msg)
	{
		std::lock_guard<std::mutex> _lock(_Globals::_GlobalMutex_debug);

		FJORDIMM3DENGINE_DEBUG_ASSERT(msg != nullptr);

		std::fprintf(stderr, "%s[[[ DEBUG ]]]%s %s\n", PRINTCOLOR_DEBUG, PRINTCOLOR_NONE, msg);
		std::fflush(stderr);
	}

	void LogWarning(char const* msg)
	{
		std::lock_guard<std::mutex> _lock(_Globals::_GlobalMutex_debug);

		FJORDIMM3DENGINE_DEBUG_ASSERT(msg != nullptr);

		std::fprintf(stderr, "%s[[[ WARNING ]]]%s %s\n", PRINTCOLOR_WARNING, PRINTCOLOR_NONE, msg);
		std::fflush(stderr);
	}

	void LogNonfatalError(char const* msg)
	{
		std::lock_guard<std::mutex> _lock(_Globals::_GlobalMutex_debug);

		FJORDIMM3DENGINE_DEBUG_ASSERT(msg != nullptr);

		std::fprintf(stderr, "%s[[[ NONFATAL ERROR ]]]%s %s\n", PRINTCOLOR_ERROR, PRINTCOLOR_NONE, msg);
		std::fflush(stderr);
	}

	void LogFatalError(char const* msg)
	{
		std::lock_guard<std::mutex> _lock(_Globals::_GlobalMutex_debug);

		FJORDIMM3DENGINE_DEBUG_ASSERT(msg != nullptr);
		
		std::fprintf(stderr, "%s[[[ FATAL ERROR ]]]%s %s\n", PRINTCOLOR_ERROR, PRINTCOLOR_NONE, msg);
		std::fflush(stderr);
		std::exit(EXIT_FAILURE);
	}

	void Printf(char const* const format, ...)
	{
		std::lock_guard<std::mutex> _lock(_Globals::_GlobalMutex_debug);

		FJORDIMM3DENGINE_DEBUG_ASSERT(format != nullptr);

		std::va_list argptr;
		va_start(argptr, format);
		std::vfprintf(stderr, format, argptr);
		std::fflush(stderr);
		va_end(argptr);
	}

	void Logf(char const* const format, ...)
	{
		std::lock_guard<std::mutex> _lock(_Globals::_GlobalMutex_debug);

		FJORDIMM3DENGINE_DEBUG_ASSERT(format != nullptr);

		std::va_list argptr;
		va_start(argptr, format);
		std::fprintf(stderr, "%s[[[ DEBUG ]]]%s ", PRINTCOLOR_DEBUG, PRINTCOLOR_NONE);
		std::vfprintf(stderr, format, argptr);
		std::fprintf(stderr, "\n");
		std::fflush(stderr);
		va_end(argptr);
	}

	void Exit()
	{
		std::lock_guard<std::mutex> _lock(_Globals::_GlobalMutex_debug);

		std::fprintf(stderr, "%s[[[ EXITING ]]]%s\n", PRINTCOLOR_ERROR, PRINTCOLOR_NONE);
		std::fflush(stderr);
		std::exit(EXIT_FAILURE);
	}

	void _Assert(bool expr, int lineNum, char const* filename)
	{
		std::lock_guard<std::mutex> _lock(_Globals::_GlobalMutex_debug);

		FJORDIMM3DENGINE_DEBUG_ASSERT(filename != nullptr);

		if (!expr)
		{
			std::fprintf(stderr, "%s[[[ ASSERTION FAILED ]]] at line %d in \"%s\"%s\n", PRINTCOLOR_ERROR, lineNum, filename, PRINTCOLOR_NONE);
			std::fflush(stderr);
			std::exit(EXIT_FAILURE);
		}
	}
}

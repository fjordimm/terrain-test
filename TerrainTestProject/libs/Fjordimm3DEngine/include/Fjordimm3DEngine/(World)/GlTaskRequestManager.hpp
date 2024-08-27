
#pragma once

#include <mutex>
#include <future>

namespace Fjordimm3DEngine
{
	class GlTaskRequestManager
	{
		/* Constructors */

	   public:
		GlTaskRequestManager(GlTaskRequestManager const&) = delete;
		GlTaskRequestManager& operator=(GlTaskRequestManager const&) = delete;
		
		GlTaskRequestManager();
		
		/* Fields */

	   private:
		std::mutex mut;

		/* Methods */

	   private:
		template <typename Dog, typename ...Args>
		static float doFunctionCall(Dog* dog, Args&&... args)
		{
			// return std::forward<Function>(func)(std::forward<Args>(args)...);
			// return (*func)(1, 2);
			// return func(1, 2);
			return dog(args...);
		}

	   public:
		template <typename Function, typename ...Args>
		std::future<float> request(Function* func, Args&&... args)
		{
			char c = 3;
			return std::async(std::launch::async, doFunctionCall<Function, Args&&...>, func, args...);
			// return std::async(std::launch::async, &func, args...);
		}
	};
}

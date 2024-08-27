
#include "Fjordimm3DEngine/(PtrForGlfw)/PtrForGlfw.hpp"

#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	PtrForGlfw::PtrForGlfw() :
		classMap()
	{}

	/* Methods */

	void PtrForGlfw::bindToGlfwWindow(GLFWwindow* windowForGlfw)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(windowForGlfw != nullptr);

		glfwSetWindowUserPointer(windowForGlfw, this);

		Debug::Log("f24");
		Debug::CheckOpenGLErrors();
	}
	
	/* Functions */
	
	PtrForGlfw* PtrForGlfw::Retrieve(GLFWwindow* windowForGlfw)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(windowForGlfw != nullptr);

		PtrForGlfw* ret = (PtrForGlfw*)glfwGetWindowUserPointer(windowForGlfw);
		Debug::Log("f25");
		Debug::CheckOpenGLErrors();
		return ret;
	}
}

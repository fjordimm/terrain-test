
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
	}
	
	/* Functions */
	
	PtrForGlfw* PtrForGlfw::Retrieve(GLFWwindow* windowForGlfw)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(windowForGlfw != nullptr);

		return (PtrForGlfw*)glfwGetWindowUserPointer(windowForGlfw);
	}
}

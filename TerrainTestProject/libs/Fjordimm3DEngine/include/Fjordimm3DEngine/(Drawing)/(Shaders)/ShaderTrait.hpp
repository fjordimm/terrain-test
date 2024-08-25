
#pragma once

#include <cstdlib>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Fjordimm3DEngine/(headerGroups)/glmGroup.hpp"
#include "Fjordimm3DEngine/(Drawing)/FormDrawContent.hpp"

namespace Fjordimm3DEngine
{
	class ShaderTrait
	{
		/* Constructors */

	   public:
		ShaderTrait(ShaderTrait const&) = delete;
		ShaderTrait& operator=(ShaderTrait const&) = delete;
		
		ShaderTrait();

		/* Methods */

	   public:
		virtual void enableAttribsForMesh(std::size_t stride, void* strideOffset) = 0;
		virtual std::size_t attribsSize() = 0;
		virtual void setupAttributes(GLuint program) = 0;
		virtual void setupUniforms(GLuint program) = 0;
		virtual void updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const = 0;
	};
}

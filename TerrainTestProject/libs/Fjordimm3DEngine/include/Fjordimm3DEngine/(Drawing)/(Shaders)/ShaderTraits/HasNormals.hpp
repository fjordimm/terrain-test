
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	class HasNormals : public ShaderTrait
	{
		/* Constructors */

	   public:
		HasNormals(HasNormals const&) = delete;
		HasNormals& operator=(HasNormals const&) = delete;
		
		HasNormals();

		/* Fields */

	   private:
		GLint attribNormal;

		/* Methods */

	   public:
		void enableAttribsForMesh(std::size_t stride, void* strideOffset) final;
		std::size_t attribsSize() final;
		void setupAttributes(GLuint program) final;
		void setupUniforms(GLuint program) final;
		void updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const final;
	};
}

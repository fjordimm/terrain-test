
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	class HasTexture : public ShaderTrait
	{
		/* Constructors */

	   public:
		HasTexture(HasTexture const&) = delete;
		HasTexture& operator=(HasTexture const&) = delete;
		
		HasTexture();

		/* Fields */

	   private:
		GLint attribTextureCoord;
		
		GLint uniHasTexture;
		GLint uniTextureSampler0;

		/* Methods */

	   public:
		void enableAttribsForMesh(std::size_t stride, void* strideOffset) final;
		std::size_t attribsSize() final;
		void setupAttributes(GLuint program) final;
		void setupUniforms(GLuint program) final;
		void updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const final;

		void setUniHasTexture(bool val) const;
	};
}

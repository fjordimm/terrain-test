
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	class HasTexture : public ShaderTrait
	{
		/* Constructors */

	   public:
		HasTexture(const HasTexture&) = delete;
		HasTexture& operator=(const HasTexture&) = delete;
		
		HasTexture();

		/* Fields */

	   private:
		GLint uniTextureSampler0;
		GLint uniTextureSampler1;

		/* Methods */

	   public:
		void enableAttribsForMesh(std::size_t stride) final;
		std::size_t attribsSize() final;
		void setupAttributes(GLuint program) final;
		void setupUniforms(GLuint program) final;
		void updateUniformsFromTran(Tran& tran) const final;
	};
}

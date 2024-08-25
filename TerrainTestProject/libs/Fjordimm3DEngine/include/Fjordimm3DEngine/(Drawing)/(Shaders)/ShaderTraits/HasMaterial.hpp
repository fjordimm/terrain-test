
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	class HasMaterial : public ShaderTrait
	{
		/* Constructors */

	   public:
		HasMaterial(HasMaterial const&) = delete;
		HasMaterial& operator=(HasMaterial const&) = delete;
		
		HasMaterial();

		/* Fields */

	   private:
		GLint uniMaterialColor;

		/* Methods */

	   public:
		void enableAttribsForMesh(std::size_t stride, void* strideOffset) final;
		std::size_t attribsSize() final;
		void setupAttributes(GLuint program) final;
		void setupUniforms(GLuint program) final;
		void updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const final;

		void setUniMaterialColor(glm::vec4 val) const;
	};
}

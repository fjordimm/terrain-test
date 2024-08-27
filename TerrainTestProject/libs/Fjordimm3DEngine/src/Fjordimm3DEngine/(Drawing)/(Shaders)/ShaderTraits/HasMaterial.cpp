
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/HasMaterial.hpp"

#include <memory>
#include <vector>
#include "Fjordimm3DEngine/(FileLoading)/FileLoading.hpp"
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	/* Constructors */

	HasMaterial::HasMaterial() :
		uniMaterialColor(-1)
	{}

	/* Methods */

	void HasMaterial::enableAttribsForMesh(std::size_t stride, void* strideOffset)
	{}

	std::size_t HasMaterial::attribsSize()
	{
		return 0;
	}

	void HasMaterial::setupAttributes(GLuint program)
	{}

	void HasMaterial::setupUniforms(GLuint program)
	{
		this->uniMaterialColor = glGetUniformLocation(program, "uni_MaterialColor");
		glm::vec4 uniMaterialColor_val = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		glUniform4fv(this->uniMaterialColor, 1, glm::value_ptr(uniMaterialColor_val));

		FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR();
	}

	void HasMaterial::updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(formDrawContent != nullptr);

		this->setUniMaterialColor(formDrawContent->materialColor.toVec4());
	}

	void HasMaterial::setUniMaterialColor(glm::vec4 val) const
	{ glUniform4fv(this->uniMaterialColor, 1, glm::value_ptr(val)); FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR(); }
}

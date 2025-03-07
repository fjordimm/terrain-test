
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/HasNormals.hpp"

#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	/* Constructors */

	HasNormals::HasNormals() :
		attribNormal(-1)
	{}

	/* Methods */

	void HasNormals::enableAttribsForMesh(std::size_t stride, void* strideOffset)
	{
		glEnableVertexAttribArray(this->attribNormal);
		glVertexAttribPointer(this->attribNormal, 3, GL_FLOAT, GL_FALSE, stride, strideOffset);

		FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR();
	}

	std::size_t HasNormals::attribsSize()
	{
		return 3 * sizeof(float);
	}

	void HasNormals::setupAttributes(GLuint program)
	{
		this->attribNormal = glGetAttribLocation(program, "attrib_Normal");
		
		FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR();
	}

	void HasNormals::setupUniforms(GLuint program)
	{}

	void HasNormals::updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(formDrawContent != nullptr);
	}
}

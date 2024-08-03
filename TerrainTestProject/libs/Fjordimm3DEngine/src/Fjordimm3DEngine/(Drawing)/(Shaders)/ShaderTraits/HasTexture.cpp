
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/HasTexture.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	/* Constructors */

	HasTexture::HasTexture() :
		uniTextureSampler(-1)
	{}

	/* Methods */

	void HasTexture::enableAttribsForMesh(std::size_t stride)
	{
	}

	std::size_t HasTexture::attribsSize()
	{
		return 0;
	}

	void HasTexture::setupAttributes(GLuint program)
	{
	}

	void HasTexture::setupUniforms(GLuint program)
	{
		this->uniTextureSampler = glGetUniformLocation(program, "uni_TextureSampler");
		glUniform1i(this->uniTextureSampler, 0);
	}

	void HasTexture::updateUniformsFromTran(Tran& tran) const {}
}

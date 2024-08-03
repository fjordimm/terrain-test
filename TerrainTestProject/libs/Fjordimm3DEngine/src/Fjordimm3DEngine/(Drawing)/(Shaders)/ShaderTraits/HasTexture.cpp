
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/HasTexture.hpp"

#include <memory>
#include <vector>
#include "Fjordimm3DEngine/(FileLoading)/FileLoading.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	/* Constructors */

	HasTexture::HasTexture() :
		uniTextureSampler0(-1),
		uniTextureSampler1(-1)
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
		this->uniTextureSampler0 = glGetUniformLocation(program, "uni_TextureSampler0");
		glUniform1i(this->uniTextureSampler0, 0);

		this->uniTextureSampler1 = glGetUniformLocation(program, "uni_TextureSampler1");
		glUniform1i(this->uniTextureSampler1, 1);
	}

	void HasTexture::updateUniformsFromTran(Tran& tran) const {}
}

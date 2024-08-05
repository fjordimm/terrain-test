
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/HasTexture.hpp"

#include <memory>
#include <vector>
#include "Fjordimm3DEngine/(FileLoading)/FileLoading.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	/* Constructors */

	HasTexture::HasTexture() :
		uniHasTexture(-1),
		uniTextureSampler0(-1)
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
		this->uniHasTexture = glGetUniformLocation(program, "uni_HasTexture");
		glUniform1i(this->uniHasTexture, false);

		this->uniTextureSampler0 = glGetUniformLocation(program, "uni_TextureSampler0");
		glUniform1i(this->uniTextureSampler0, 0);

		// this->uniTextureSampler1 = glGetUniformLocation(program, "uni_TextureSampler1");
		// glUniform1i(this->uniTextureSampler1, 1);
	}

	void HasTexture::updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const
	{
		this->setUniHasTexture(formDrawContent->texture);
	}

	void HasTexture::setUniHasTexture(bool val) const
	{ glUniform1i(this->uniHasTexture, val); }
}

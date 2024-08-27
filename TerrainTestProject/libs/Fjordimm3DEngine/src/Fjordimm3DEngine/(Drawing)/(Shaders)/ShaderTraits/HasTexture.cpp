
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/HasTexture.hpp"

#include <memory>
#include <vector>
#include "Fjordimm3DEngine/(FileLoading)/FileLoading.hpp"
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	/* Constructors */

	HasTexture::HasTexture() :
		attribTextureCoord(-1),
		uniHasTexture(-1),
		uniTextureSampler0(-1)
	{}

	/* Methods */

	void HasTexture::enableAttribsForMesh(std::size_t stride, void* strideOffset)
	{
		glEnableVertexAttribArray(this->attribTextureCoord);
		glVertexAttribPointer(this->attribTextureCoord, 2, GL_FLOAT, GL_FALSE, stride, strideOffset);

		Debug::CheckOpenGLErrors();
	}

	std::size_t HasTexture::attribsSize()
	{
		return 2 * sizeof(float);
	}

	void HasTexture::setupAttributes(GLuint program)
	{
		this->attribTextureCoord = glGetAttribLocation(program, "attrib_TextureCoord");
	}

	void HasTexture::setupUniforms(GLuint program)
	{
		this->uniHasTexture = glGetUniformLocation(program, "uni_HasTexture");
		glUniform1i(this->uniHasTexture, false);

		this->uniTextureSampler0 = glGetUniformLocation(program, "uni_TextureSampler0");
		glUniform1i(this->uniTextureSampler0, 0);

		// this->uniTextureSampler1 = glGetUniformLocation(program, "uni_TextureSampler1");
		// glUniform1i(this->uniTextureSampler1, 1);

		Debug::CheckOpenGLErrors();
	}

	void HasTexture::updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const
	{
		this->setUniHasTexture(formDrawContent->texture != nullptr);
	}

	void HasTexture::setUniHasTexture(bool val) const
	{ glUniform1i(this->uniHasTexture, val); Debug::CheckOpenGLErrors(); }
}

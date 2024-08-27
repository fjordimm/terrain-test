
#include "Fjordimm3DEngine/(Drawing)/(Textures)/Texture.hpp"

#include <memory>
#include <vector>
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(FileLoading)/FileLoading.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allShaderTraits.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	Texture::Texture()
	{
		for (std::size_t i = 0; i < NumTexs; i++)
		{
			this->texs[i] = (GLuint)(-1);
		}
	}

	std::unique_ptr<Texture> Texture::New()
	{
		std::unique_ptr<Texture> ret = std::make_unique<Texture>();
		return ret;
	}

	/* Methods */

	void Texture::initializeTextureForGl(std::size_t index, std::string const& filename)
	{
		if (index < 0 || index >= NumTexs)
		{
			Debug::LogNonfatalError("Tried to set a texture with an index out of bounds.");
		}

		glGenTextures(1, &this->texs[index]);

		glActiveTexture(GL_TEXTURE0 + index);
		glBindTexture(GL_TEXTURE_2D, this->texs[index]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		std::size_t imageWidth;
		std::size_t imageHeight;
		std::unique_ptr<std::vector<unsigned char>> image = FileLoading::LoadImage(filename, imageWidth, imageHeight);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->data());
		
		Debug::CheckOpenGLErrors();
	}

	void Texture::useForGl(ShaderTraits::HasTexture const* hasTextureTrait)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(hasTextureTrait != nullptr);
		
		for (std::size_t i = 0; i < NumTexs; i++)
		{
			if (this->texs[i] != (GLuint)(-1))
			{
				GLint uniTextureSampler = hasTextureTrait->getUniTextureSampler(i);

				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, this->texs[i]);
				glUniform1i(uniTextureSampler, i);
				
				Debug::CheckOpenGLErrors();
			}
		}
	}
}

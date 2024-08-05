
#include "Fjordimm3DEngine/(Drawing)/(Textures)/Texture.hpp"

#include <memory>
#include <vector>
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(FileLoading)/FileLoading.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	Texture::Texture()
	{
		for (int i = 0; i < NumTexs; i++)
		{
			this->texs[i] = -1;
		}
	}

	std::unique_ptr<Texture> Texture::New()
	{
		std::unique_ptr<Texture> ret = std::make_unique<Texture>();
		return std::move(ret);
	}

	/* Methods */

	void Texture::initializeTextureForGl(int index, const std::string& filename)
	{
		if (index < 0 || index >= NumTexs)
		{
			Debug::LogNonfatalError("Tried to set a texture with an index out of bounds.");
		}

		glGenTextures(1, &this->texs[index]);

		glBindTextureUnit(index, this->texs[index]);

		std::size_t imageWidth;
		std::size_t imageHeight;
		std::unique_ptr<std::vector<unsigned char>> image = FileLoading::LoadImage(filename, imageWidth, imageHeight);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->data());

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	void Texture::useForGl()
	{
		for (int i = 0; i < NumTexs; i++)
		{
			if (this->texs[i] != -1)
			{
				glBindTextureUnit(i, this->texs[i]);
			}
		}
	}

	// GLenum Texture::TextureEnumForGl(int index)
	// {
	// 	switch (index)
	// 	{
	// 	case 0:
	// 		return GL_TEXTURE0;
	// 	case 1:
	// 		return GL_TEXTURE1;
	// 	case 2:
	// 		return GL_TEXTURE2;
	// 	case 3:
	// 		return GL_TEXTURE3;
	// 	case 4:
	// 		return GL_TEXTURE4;
	// 	case 5:
	// 		return GL_TEXTURE5;
	// 	case 6:
	// 		return GL_TEXTURE6;
	// 	case 7:
	// 		return GL_TEXTURE7;
	// 	case 8:
	// 		return GL_TEXTURE8;
	// 	case 9:
	// 		return GL_TEXTURE9;
	// 	case 10:
	// 		return GL_TEXTURE10;
	// 	case 11:
	// 		return GL_TEXTURE11;
	// 	case 12:
	// 		return GL_TEXTURE12;
	// 	case 13:
	// 		return GL_TEXTURE13;
	// 	// Can do more cases, up to 32
	// 	default:
	// 		Debug::LogFatalError("Tried to get a texture id with an index out of bounds.");
	// 		return GL_INVALID_ENUM;
	// 	}
	// }
}


#pragma once

#include <memory>
#include <string>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Fjordimm3DEngine
{
	// Forward Declarations
	namespace ShaderTraits { class HasTexture; }

	class Texture
	{
		/* Constants */

	   public:
		static constexpr int NumTexs = 1; // must match the number of uni texture samplers in ShaderTraits::HasTexture

		/* Constructors */

	   private:
		Texture(Texture const&) = delete;
		Texture& operator=(Texture const&) = delete;
		
		Texture();

	   public:
		static std::unique_ptr<Texture> New();
		
		/* Fields */

	   private:
		GLuint texs[NumTexs];

		/* Methods */

	   public:
		void initializeTextureForGl(ShaderTraits::HasTexture const* hasTextureTrait, int index, std::string const& filename);
		void useForGl(ShaderTraits::HasTexture const* hasTextureTrait);

	//    private:
	// 	static GLenum TextureEnumForGl(int index);

		/* Friends */

		friend std::unique_ptr<Texture> std::make_unique<Fjordimm3DEngine::Texture>();
	};

	// TODO: glGenerateMipmap()
}

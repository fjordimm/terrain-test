
#pragma once

#include <memory>
#include <string>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Fjordimm3DEngine
{
	class Texture
	{
		/* Constants */

	   public:
		static constexpr int NumTexs = 6;

		/* Constructors */

	   private:
		Texture(const Texture&) = delete;
		Texture& operator=(const Texture&) = delete;
		
		Texture();

	   public:
		static std::unique_ptr<Texture> New();
		
		/* Fields */

	   private:
		GLuint texs[NumTexs];

		/* Methods */

	   public:
		void initializeTextureForGl(int index, const std::string& filename);
		void useForGl();

	//    private:
	// 	static GLenum TextureEnumForGl(int index);

		/* Friends */

		friend std::unique_ptr<Texture> std::make_unique<Fjordimm3DEngine::Texture>();
	};

	// TODO: glGenerateMipmap()
}

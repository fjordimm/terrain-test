
#pragma once

#include <map>
#include <typeinfo>
#include <unordered_set>
#include <tuple>
#include <cstdlib>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Fjordimm3DEngine/(Drawing)/FormDrawContent.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.hpp"

namespace Fjordimm3DEngine
{
	class ShaderProgram
	{
		/* Constructors */

	   public:
		ShaderProgram(ShaderProgram const&) = delete;
		ShaderProgram& operator=(ShaderProgram const&) = delete;
		
		ShaderProgram();
		
		~ShaderProgram();
		
		/* Fields */

	   private:
		std::map<std::size_t, ShaderTrait*> traits;
		std::size_t stride;
		
		GLuint vertexShader;
		GLuint geometryShader;
		GLuint fragmentShader;

		std::unordered_set<FormDrawContent*> formDrawContents;

	   protected:
		GLuint program;

		/* Methods */

	   public:
		void compileAndActivate();
		void useForGl() const;

		void addFormDrawContent(FormDrawContent* formDrawContent);
		void removeFormDrawContent(FormDrawContent* formDrawContent);
		void drawAllForms() const;

		void enableAttribsForMesh();

		template <class T, typename std::enable_if<std::is_base_of<ShaderTrait, T>::value>::type* = nullptr>
		T* tryGetTrait() const
		{
			std::map<std::size_t, ShaderTrait*>::const_iterator tryGet = this->traits.find(typeid(T).hash_code());
			if (tryGet == this->traits.end())
			{ return nullptr; }
			else
			{ return dynamic_cast<T*>(tryGet->second); }
		}

	   protected:
		void registerTrait(ShaderTrait* trait);

		virtual char const* getVertexShaderSourcePath() const = 0;
		virtual char const* getGeometryShaderSourcePath() const = 0;
		virtual char const* getFragmentShaderSourcePath() const = 0;

	   private:
		void cleanupForGl();
		static void CheckShaderCompilation(GLuint shader);
	};
}

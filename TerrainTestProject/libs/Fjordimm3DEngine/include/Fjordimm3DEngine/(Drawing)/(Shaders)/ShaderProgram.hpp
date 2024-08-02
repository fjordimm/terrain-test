
#pragma once

#include <unordered_map>
#include <typeinfo>
#include <list>
#include <tuple>
#include <cstdlib>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Fjordimm3DEngine/(Util)/(Tran)/Tran.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/MeshVertAttribs.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.hpp"

namespace Fjordimm3DEngine
{
	class ShaderProgram
	{
		/* Constructors */

	   public:
		ShaderProgram(const ShaderProgram&) = delete;
		ShaderProgram& operator=(const ShaderProgram&) = delete;
		
		ShaderProgram();
		
		/* Fields */

	   private:
		std::unordered_map<std::size_t, ShaderTrait*> traits;
		std::size_t stride;
		
		GLuint vertexShader;
		GLuint geometryShader;
		GLuint fragmentShader;

		std::list<std::tuple<Mesh*, Tran*>> trans;

	   protected:
		GLuint program;

		/* Methods */

	   public:
		void compileAndActivate();
		void use() const;

		std::list<std::tuple<Mesh*, Tran*>>::const_iterator addForm(Mesh* mesh, Tran* tran);
		void removeForm(const std::list<std::tuple<Mesh*, Tran*>>::const_iterator& iter);
		void drawAllTrans() const;

		void enableAttribsForMesh();

		template <class T, typename std::enable_if<std::is_base_of<ShaderTrait, T>::value>::type* = nullptr>
		T* tryGetTrait() const
		{
			std::unordered_map<std::size_t, ShaderTrait*>::const_iterator tryGet = this->traits.find(typeid(T).hash_code());
			if (tryGet == this->traits.end())
			{ return nullptr; }
			else
			{ return dynamic_cast<T*>(tryGet->second); }
		}

	   protected:
		void registerTrait(ShaderTrait* trait);

		virtual const char* getVertexShaderSourcePath() const = 0;
		virtual const char* getGeometryShaderSourcePath() const = 0;
		virtual const char* getFragmentShaderSourcePath() const = 0;

	   private:
		void checkShaderCompilation(GLuint shader) const;
	};

	// TODO: cleanup gl shaders and shader programs
}

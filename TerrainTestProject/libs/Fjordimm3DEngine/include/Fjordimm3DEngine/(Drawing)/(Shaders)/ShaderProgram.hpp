
#pragma once

#include <list>
#include <tuple>
#include <cstdlib>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Fjordimm3DEngine/(Util)/(Tran)/Tran.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/MeshVertAttribs.hpp"

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
		
		virtual MeshVertAttribs attribFlagsForMeshSamples() const = 0;

		virtual void enableAttribsForMesh() = 0;

	   protected:
		virtual const char* getVertexShaderSourcePath() const = 0;
		virtual const char* getGeometryShaderSourcePath() const = 0;
		virtual const char* getFragmentShaderSourcePath() const = 0;

		virtual std::size_t getStride() = 0;
		
		virtual void setupUniforms() = 0;
		virtual void setupAttributes() = 0;
		virtual void updateUniformsFromTran(Tran& tran) const = 0;

	   private:
		void checkShaderCompilation(GLuint shader) const;
	};

	// TODO: cleanup gl shaders and shader programs
}

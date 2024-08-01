
#pragma once

#include <unordered_map>
#include <memory>
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSample.hpp"

namespace Fjordimm3DEngine
{
	class MeshManager
	{
		/* Constructors */

	   public:
		MeshManager(const MeshManager&) = delete;
		MeshManager& operator=(const MeshManager&) = delete;
		
		MeshManager();
		
		/* Fields */

	   private:
		std::unordered_map<Mesh*, std::unique_ptr<Mesh>> meshes;

		/* Methods */

	   public:
		Mesh* add(ShaderProgram* shaderProgram, std::unique_ptr<MeshData> meshData); // Only to be used after the main loop has started
		Mesh* add(ShaderProgram* shaderProgram, const MeshSample& meshSample); // Only to be used after the main loop has started
		void remove(Mesh* mesh);
	};
}

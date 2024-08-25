
#pragma once

#include "Fjordimm3DEngine/(World)/Head.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainManager.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	class TerrainTestHead : public Head
	{
		/* Constructors */

	   public:
		TerrainTestHead(const TerrainTestHead&) = delete;
		TerrainTestHead& operator=(const TerrainTestHead&) = delete;

		TerrainTestHead();
		
		/* Fields */

	   private:
		ShaderProgram* flatShaderProgram;
		ShaderProgram* smoothShaderProgram;
		std::unique_ptr<Mesh> cubeMesh;
		std::unique_ptr<Mesh> sphereMesh;
		TerrainManager terrainManager;

		/* Methods */

	   private:
		void initializeShadersAndFixedMeshes();

	   protected:
		void onStart() final;
		void onUpdate(float deltaTime) final;
	};
}

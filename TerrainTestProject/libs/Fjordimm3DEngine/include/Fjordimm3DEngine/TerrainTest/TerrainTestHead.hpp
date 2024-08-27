
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
		TerrainTestHead(TerrainTestHead const&) = delete;
		TerrainTestHead& operator=(TerrainTestHead const&) = delete;

		TerrainTestHead();
		
		/* Fields */

	   private:
		ShaderProgram* flatShaderProgram;
		ShaderProgram* smoothShaderProgram;
		std::unique_ptr<Texture> texture1;
		std::unique_ptr<Mesh> cubeMesh;
		std::unique_ptr<Mesh> sphereMesh;
		std::unique_ptr<Mesh> sphereMesh2;
		TerrainManager terrainManager;

		/* Methods */

	   private:
		void initializeShadersAndFixedMeshes();

	   protected:
		void onStart() final;
		void onUpdate(float deltaTime) final;
		void onFinish() final;
	};
}

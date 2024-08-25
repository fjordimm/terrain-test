
#pragma once

#include <memory>
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.hpp"
#include "Fjordimm3DEngine/(World)/WorldState.hpp"
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainGene.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	class TerrainManager
	{
		/* Subclasses */

	   private:
		class Chunk
		{
			/* Constructors */

		   public:
			Chunk(const Chunk&) = delete;
			Chunk& operator=(const Chunk&) = delete;
			
			Chunk();

			/* Fields */

		   public:
			std::unique_ptr<Mesh> mesh;

			/* Methods */
		};

		/* Constructors */

	   public:
		TerrainManager(const TerrainManager&) = delete;
		TerrainManager& operator=(const TerrainManager&) = delete;
		
		TerrainManager();
		
		/* Fields */

	   private:
		TerrainGene terrainGene;
		
		std::unique_ptr<Mesh> mesh1;
		std::unique_ptr<Mesh> mesh2;

		/* Methods */

	   public:
		void beginGeneration(WorldState& worldState, ShaderProgram* shaderProgram);
	};
}

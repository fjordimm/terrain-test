
#pragma once

#include <memory>
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.hpp"
#include "Fjordimm3DEngine/(World)/WorldState.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	class TerrainManager
	{
		/* Constructors */

	   public:
		TerrainManager(const TerrainManager&) = delete;
		TerrainManager& operator=(const TerrainManager&) = delete;
		
		TerrainManager();
		
		/* Fields */

	   private:
		std::unique_ptr<Mesh> mesh1;

		/* Methods */

	   public:
		void beginGeneration(WorldState& worldState, ShaderProgram* shaderProgram);
	};
}

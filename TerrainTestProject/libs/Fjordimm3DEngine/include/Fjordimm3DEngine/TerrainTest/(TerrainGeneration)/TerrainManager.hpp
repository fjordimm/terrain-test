
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
			Chunk() = delete;
			Chunk(Chunk const&) = delete;
			Chunk& operator=(Chunk const&) = delete;
			
			Chunk(Form* form);

			/* Fields */

		   private:
			std::unique_ptr<Mesh> mesh;
			Form* form;

			/* Getters and Setters */

		   public:
			inline Form* const& getForm() const { return this->form; }

			/* Methods */
		};

		/* Constructors */

	   public:
		TerrainManager(TerrainManager const&) = delete;
		TerrainManager& operator=(TerrainManager const&) = delete;
		
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

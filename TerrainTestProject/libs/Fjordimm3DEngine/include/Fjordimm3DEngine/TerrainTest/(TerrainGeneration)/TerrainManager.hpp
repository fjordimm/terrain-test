
#pragma once

#include <memory>
#include <list>
#include <mutex>
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.hpp"
#include "Fjordimm3DEngine/(World)/WorldState.hpp"
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainGene.hpp"
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/ChunkMesh.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	class TerrainManager
	{
		/* Subclasses */

	   public:
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
			Form* form;
			std::unique_ptr<Mesh> mesh;

			/* Getters and Setters */

		   public:
			inline Form* const& getForm() const { return this->form; }

			/* Methods */

		   public:
			void setMesh(std::unique_ptr<Mesh> mesh);
		};

		/* Constructors */

	   public:
		TerrainManager(TerrainManager const&) = delete;
		TerrainManager& operator=(TerrainManager const&) = delete;
		
		TerrainManager();
		
		/* Fields */

	   private:
		TerrainGene terrainGene;
		std::list<std::unique_ptr<Chunk>> chunks;
		std::mutex mut_chunks;

		/* Methods */

	   public:
		void beginGeneration(WorldState& worldState, ShaderProgram* shaderProgram);

		/* Functions */

	   private:
		// static void makeChunk(std::list<std::unique_ptr<Chunk>>* chunks, std::mutex* mut_chunks, WorldState* worldState, ShaderProgram* shaderProgram, TerrainGene* terrainGene, std::int64_t size, float chunkScale, std::int64_t xOff, std::int64_t yOff);
		// static void makeChunk(std::list<std::unique_ptr<Chunk>>* chunks, std::mutex* mut_chunks, WorldState* worldState, ShaderProgram* shaderProgram, TerrainGene* terrainGene, std::int64_t size, float chunkScale, std::int64_t xOff, std::int64_t yOff);
	};
}

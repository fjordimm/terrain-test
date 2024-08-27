
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainManager.hpp"

#include <future>
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(Form)/PhysicForm.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Subclass 'Chunk' */

		/* Constructors */

		TerrainManager::Chunk::Chunk(Form* form) :
			form(form),
			mesh(nullptr)
		{}

		/* Methods */

		void TerrainManager::Chunk::setMesh(std::unique_ptr<Mesh> mesh)
		{
			this->mesh = std::move(mesh);

			this->form->changeMesh(this->mesh.get());
		}

	/* Constructors */

	TerrainManager::TerrainManager() :
		terrainGene(77832752),
		chunks(),
		mut_chunks()
	{}

	/* Methods */

	void TerrainManager::beginGeneration(WorldState& worldState, ShaderProgram* shaderProgram)
	{
		std::int64_t n = 1;
		std::int64_t s = 60;
		for (std::int64_t x = 0; x < n; x++)
		{
			for (std::int64_t y = 0; y < n; y++)
			{
				// std::unique_ptr<Chunk> chunk = std::make_unique<Chunk>(worldState.forms.add(Form::New(worldState)));
				// chunk->setMesh(Mesh::New(shaderProgram, ChunkMesh(terrainGene, s, 1.0f, x, y, LodTransitions::None)));
				// this->chunks.push_back(std::move(chunk));
				
				makeChunk(&this->chunks, &this->mut_chunks, &worldState, shaderProgram, &this->terrainGene, s, 1.0f, x, y);
			}
		}
	}

	void TerrainManager::makeChunk(std::list<std::unique_ptr<Chunk>>* chunks, std::mutex* mut_chunks, WorldState* worldState, ShaderProgram* shaderProgram, TerrainGene* terrainGene, std::int64_t size, float chunkScale, std::int64_t xOff, std::int64_t yOff)
	{
		std::unique_ptr<TerrainManager::Chunk> chunk = std::make_unique<TerrainManager::Chunk>(worldState->forms.add(Form::New(*worldState)));
		chunk->setMesh(Mesh::New(shaderProgram, ChunkMesh(*terrainGene, size, 1.0f, xOff, yOff, LodTransitions::None)));
		
		// {
		// 	std::lock_guard<std::mutex> _lock(*mut_chunks);

		// 	chunks->push_back(std::move(chunk));
		// }
	}
}

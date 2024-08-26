
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainManager.hpp"

#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/ChunkMesh.hpp"
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
		terrainGene(35935932),
		chunks()
	{}

	/* Methods */

	void TerrainManager::beginGeneration(WorldState& worldState, ShaderProgram* shaderProgram)
	{
		// {
		// 	std::unique_ptr<Chunk> chunk = std::make_unique<Chunk>(worldState.forms.add(Form::New(worldState)));
		// 	chunk->setMesh(Mesh::New(shaderProgram, ChunkMesh(terrainGene, 30, 2.0f, 0, 0, LodTransitions::None)));
		// 	this->chunks.push_back(std::move(chunk));
		// }

		std::int64_t n = 1;
		std::int64_t s = 500;
		for (std::int64_t x = 0; x < n; x++)
		{
			for (std::int64_t y = 0; y < n; y++)
			{
				std::unique_ptr<Chunk> chunk = std::make_unique<Chunk>(worldState.forms.add(Form::New(worldState)));
				chunk->setMesh(Mesh::New(shaderProgram, ChunkMesh(terrainGene, s, 1.0f, x, y, LodTransitions::None)));
				this->chunks.push_back(std::move(chunk));
			}
		}
	}
}

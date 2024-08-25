
#pragma once

#include <cstdint>
#include <memory>
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.hpp"
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainGene.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	enum class LodTransitions : std::uint32_t
	{
		None   = 0u,

		Left   = 1u << 0,
		Right  = 1u << 1,
		Top    = 1u << 2,
		Bottom = 1u << 3
	};

	LodTransitions operator|(LodTransitions lhs, LodTransitions rhs);
	LodTransitions operator&(LodTransitions lhs, LodTransitions rhs);
	LodTransitions operator^(LodTransitions lhs, LodTransitions rhs);
	LodTransitions operator~(LodTransitions the);
	bool operator==(LodTransitions lhs, LodTransitions rhs);
	bool operator!=(LodTransitions lhs, LodTransitions rhs);

	class ChunkMesh : public MeshSample
	{
		/* Constructors */

	   public:
		ChunkMesh(TerrainGene& terrainGene, int32_t size, float chunkScale, int64_t xOff, int64_t yOff, LodTransitions lodTransitions = LodTransitions::None);

		/* Fields */

	   private:
		TerrainGene& terrainGene;
		int32_t size;
		float chunkScale;
		int64_t xOff;
		int64_t yOff;
		LodTransitions lodTransitions;

		/* Methods */

	   protected:
		void generateData(bool doVertPositions3D, std::vector<Vec>& vertPositions3D, bool doVertNormals3D, std::vector<Vec>& vertNormals3D, bool doVertTextureCoords, std::vector<Vec2>& vertTextureCoords, std::vector<std::tuple<GLuint, GLuint, GLuint>>& triangles) const final;
	};
}

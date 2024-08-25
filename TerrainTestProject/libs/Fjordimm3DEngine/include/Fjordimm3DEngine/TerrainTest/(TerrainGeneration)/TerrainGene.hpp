
#pragma once

namespace Fjordimm3DEngine::TerrainTest
{
	class TerrainGene
	{
		/* Constructors */

	   public:
		TerrainGene(TerrainGene const&) = delete;
		TerrainGene& operator=(TerrainGene const&) = delete;
		
		TerrainGene();
		
		/* Fields */

	   private:
		// TODO: array of OpenSimplexNoise

		/* Methods */

	   public:
		float heightAt(float x, float y);
	};
}

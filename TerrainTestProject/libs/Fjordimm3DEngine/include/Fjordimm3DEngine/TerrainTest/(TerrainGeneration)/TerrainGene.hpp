
#pragma once

namespace Fjordimm3DEngine::TerrainTest
{
	class TerrainGene
	{
		/* Constructors */

	   public:
		TerrainGene(const TerrainGene&) = delete;
		TerrainGene& operator=(const TerrainGene&) = delete;
		
		TerrainGene();
		
		/* Fields */

	   private:
		// TODO: array of OpenSimplexNoise

		/* Methods */

	   public:
		float heightAt(float x, float y);
	};
}


#pragma once

#include "Fjordimm3DEngine/(Util)/(OpenSimplexNoise)/OpenSimplexNoise.hpp"

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
		OpenSimplexNoise osn;
		// TODO: array of OpenSimplexNoise

		/* Methods */

	   public:
		float heightAt(float x, float y);
	};
}

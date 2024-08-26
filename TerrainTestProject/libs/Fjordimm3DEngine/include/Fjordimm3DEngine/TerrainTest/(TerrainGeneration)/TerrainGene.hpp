
#pragma once

#include <array>
#include <memory>
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
		std::array<std::unique_ptr<OpenSimplexNoise>, 25> osnDetails;

		/* Methods */

	   public:
		float heightAt(float x, float y);
	};
}

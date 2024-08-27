
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
		TerrainGene() = delete;
		TerrainGene(TerrainGene const&) = delete;
		TerrainGene& operator=(TerrainGene const&) = delete;
		
		TerrainGene(unsigned int seed);
		
		/* Fields */

	   private:
		std::array<std::unique_ptr<OpenSimplexNoise>, 10> osnRidges;
		std::array<std::unique_ptr<OpenSimplexNoise>, 8> osnMountains;
		std::array<std::unique_ptr<OpenSimplexNoise>, 15> osnDetails;

		/* Methods */

	   public:
		float heightAt(float x, float y);
	};
}

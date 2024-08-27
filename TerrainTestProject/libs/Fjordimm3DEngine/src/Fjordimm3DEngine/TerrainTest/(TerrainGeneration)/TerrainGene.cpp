
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainGene.hpp"

#include <cmath>
#include <random>
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"
#include "Fjordimm3DEngine/(Util)/(Math)/Math.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Constructors */

	TerrainGene::TerrainGene(unsigned int seed) :
		osnRidges(),
		osnMountains(),
		osnDetails()
	{
		std::default_random_engine randomEngine(seed);
		std::uniform_int_distribution<std::int64_t> randomDistr(std::numeric_limits<std::int64_t>::min(), std::numeric_limits<std::int64_t>::max());

		for (std::size_t i = 0; i < osnRidges.size(); i++)
		{
			osnRidges[i] = std::make_unique<OpenSimplexNoise>(randomDistr(randomEngine));
		}

		for (std::size_t i = 0; i < osnMountains.size(); i++)
		{
			osnMountains[i] = std::make_unique<OpenSimplexNoise>(randomDistr(randomEngine));
		}

		for (std::size_t i = 0; i < osnDetails.size(); i++)
		{
			osnDetails[i] = std::make_unique<OpenSimplexNoise>(randomDistr(randomEngine));
		}
	}

	/* Methods */

	float TerrainGene::heightAt(float x_, float y_)
	{
		float x = 0.4f * (x_ - 0.0f);
		float y = 0.4f * (y_ - 0.0f);

		float z = 0.0f;

		float ridges = 0.0f;
		{
			float ampl = 1.9f;
			float freq = 0.006f;
			for (std::size_t i = 0; i < osnRidges.size(); i++)
			{
				float val = osnRidges[i]->eval(x * freq, y * freq);
				val = -std::abs(val) + 0.25f;

				ridges += ampl * val;
				ampl *= 0.5f;
				freq *= 1.7f;
			}
		}

		float mountains = 0.0f;
		{
			float ampl = 2.1f;
			float freq = 0.003f;
			for (std::size_t i = 0; i < osnMountains.size(); i++)
			{
				mountains += ampl * osnMountains[i]->eval(x * freq, y * freq);
				ampl *= 0.5f;
				freq *= 1.7f;
			}
		}

		float details = 0.0f;
		{
			float ampl = 0.6f;
			float freq = 0.04f;
			for (std::size_t i = 0; i < osnDetails.size(); i++)
			{
				details += ampl * osnDetails[i]->eval(x * freq, y * freq);
				ampl *= 0.5f;
				freq *= 1.7f;
			}
		}

		z = 19.7f * std::exp(ridges) * Math::Sigmoid(mountains, 0.9f, 2.7f) + 1.3f * details;

		z *= 2.5f;
		return z;
	}
}


#include "Fjordimm3DEngine/(Util)/(Math)/_functions.hpp"

#include <cmath>

namespace Fjordimm3DEngine::Math
{
	float RoughlyEqual(float a, float b, float epsilon)
	{
		return std::abs(a - b) < epsilon;
	}

	float Lerp(float a, float b, float t)
	{
		return a + t * (b - a);
	}

	float Sigmoid(float x)
	{
		return 1.0f / (1.0f + std::exp(-x));
	}

	float Sigmoid(float x, float offset, float steepness)
	{
		return 1.0f / (1.0f + std::exp(-(steepness * (x - offset))));
	}
}

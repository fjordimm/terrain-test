
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
}

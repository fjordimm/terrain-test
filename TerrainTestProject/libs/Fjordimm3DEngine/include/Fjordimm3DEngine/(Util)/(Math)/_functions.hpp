
#pragma once

#include <cmath>
#include "Fjordimm3DEngine/(Util)/(Math)/_constants.hpp"

namespace Fjordimm3DEngine::Math
{
	inline float RoughlyEqual(float a, float b, float epsilon = Math::Epsilon)
	{ return std::abs(a - b) < epsilon; }
}

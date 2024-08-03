
#pragma once

#include "Fjordimm3DEngine/(Util)/(Math)/_constants.hpp"

namespace Fjordimm3DEngine::Math
{
	float RoughlyEqual(float a, float b, float epsilon = Math::Epsilon);
	float Lerp(float a, float b, float t);
}


#pragma once

#include <string>
#include "Fjordimm3DEngine/(headerGroups)/glmGroup.hpp"
#include "Fjordimm3DEngine/(Util)/(Math)/Math.hpp"

namespace Fjordimm3DEngine
{
	typedef glm::vec2 Vec2;
	typedef glm::vec3 Vec;
	typedef glm::vec4 Vec4;

	namespace Vecs
	{
		std::string ToString(Vec const& subj);
		bool RoughlyEqual(Vec const& a, Vec const& b, float epsilon = Math::Epsilon);

		static const Vec Zero = glm::vec3(0.0f, 0.0f, 0.0f);
		static const Vec One = glm::vec3(1.0f, 1.0f, 1.0f);
		static const Vec Forwards = glm::vec3(0.0f, 1.0f, 0.0f);
		static const Vec Right = glm::vec3(1.0f, 0.0f, 0.0f);
		static const Vec Up = glm::vec3(0.0f, 0.0f, 1.0f);
	}
}

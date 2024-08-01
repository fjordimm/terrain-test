
#pragma once

#include "Fjordimm3DEngine/(headerGroups)/glmGroup.hpp"
#include "Fjordimm3DEngine/(Util)/(Tran)/Vec.hpp"

namespace Fjordimm3DEngine
{
	typedef glm::quat Quat;

	namespace Quats
	{
		static const Quat Identity = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);

		Quat Rotate(const Quat& quat, const Vec& axis, float radians);
		Quat LocallyRotate(const Quat& quat, const Vec& axis, float radians);
		Quat LookTowards(const Vec& position, const Vec& target, const Vec& up = Vecs::Up);
	}
}


#pragma once

#include "Fjordimm3DEngine/(headerGroups)/glmGroup.hpp"
#include "Fjordimm3DEngine/(Util)/(Tran)/Vec.hpp"

namespace Fjordimm3DEngine
{
	typedef glm::quat Quat;

	namespace Quats
	{
		static const Quat Identity = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);

		Quat Rotate(Quat const& quat, Vec const& axis, float radians);
		Quat LocallyRotate(Quat const& quat, Vec const& axis, float radians);
		Quat LookTowards(Vec const& position, Vec const& target, Vec const& up = Vecs::Up);
	}
}


#include "Fjordimm3DEngine/(Util)/(Tran)/Tran.hpp"

#include <sstream>
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(World)/WorldState.hpp"

namespace Fjordimm3DEngine
{
	/* Constants */

	static const glm::mat4 IdentityMat = glm::mat4(1.0f);

	/* Constructors */

	Tran::Tran() :
		_mayHaveChangedPosition(true),
		_position(Vecs::Zero),
		_mayHaveChangedRotation(true),
		_rotation(Quats::Identity),
		_mayHaveChangedScale(true),
		_scale(Vecs::One)
	{}

	Tran::Tran(Tran const& that) :
		_mayHaveChangedPosition(that._mayHaveChangedPosition),
		_position(that._position),
		_cached_positionMatrix(that._cached_positionMatrix),
		_mayHaveChangedRotation(that._mayHaveChangedRotation),
		_rotation(that._rotation),
		_cached_rotationMatrix(that._cached_rotationMatrix),
		_cached_forwardVec(that._cached_forwardVec),
		_cached_upVec(that._cached_upVec),
		_cached_rightVec(that._cached_rightVec),
		_mayHaveChangedScale(that._mayHaveChangedScale),
		_scale(that._scale),
		_cached_scaleMatrix(that._cached_scaleMatrix)
	{}

	Tran& Tran::operator=(Tran const& that)
	{
		_mayHaveChangedPosition = that._mayHaveChangedPosition;
		_position = that._position;
		_cached_positionMatrix = that._cached_positionMatrix;
		_mayHaveChangedRotation = that._mayHaveChangedRotation;
		_rotation = that._rotation;
		_cached_rotationMatrix = that._cached_rotationMatrix;
		_cached_forwardVec = that._cached_forwardVec;
		_cached_upVec = that._cached_upVec;
		_cached_rightVec = that._cached_rightVec;
		_mayHaveChangedScale = that._mayHaveChangedScale;
		_scale = that._scale;
		_cached_scaleMatrix = that._cached_scaleMatrix;
		
        return *this;
	}

	/* Getters and Setters */

	glm::mat4 const& Tran::getPositionMatrix()
	{
		if (this->_mayHaveChangedPosition)
		{
			this->_updatePositionDeps();
			this->_mayHaveChangedPosition = false;
		}

		return this->_cached_positionMatrix;
	}

	glm::mat4 const& Tran::getRotationMatrix()
	{
		if (this->_mayHaveChangedRotation)
		{
			this->_updateRotationDeps();
			this->_mayHaveChangedRotation = false;
		}

		return this->_cached_rotationMatrix;
	}

	Vec const& Tran::getForwardVec()
	{
		if (this->_mayHaveChangedRotation)
		{
			this->_updateRotationDeps();
			this->_mayHaveChangedRotation = false;
		}

		return this->_cached_forwardVec;
	}

	Vec const& Tran::getUpVec()
	{
		if (this->_mayHaveChangedRotation)
		{
			this->_updateRotationDeps();
			this->_mayHaveChangedRotation = false;
		}

		return this->_cached_upVec;
	}

	Vec const& Tran::getRightVec()
	{
		if (this->_mayHaveChangedRotation)
		{
			this->_updateRotationDeps();
			this->_mayHaveChangedRotation = false;
		}

		return this->_cached_rightVec;
	}
	
	glm::mat4 const& Tran::getScaleMatrix()
	{
		if (this->_mayHaveChangedScale)
		{
			this->_updateScaleDeps();
			this->_mayHaveChangedScale = false;
		}

		return this->_cached_scaleMatrix;
	}
	
	/* Methods */

	std::string Tran::toString() const
	{
		std::ostringstream ret;
		ret << "{pos" << Vecs::ToString(this->_position).c_str() << " rot" << Vecs::ToString(this->eulerAngles()).c_str() << " scale" << Vecs::ToString(this->_scale).c_str() << "}";
		return ret.str();
	}
	
	Vec Tran::eulerAngles() const
	{
		return glm::eulerAngles(this->_rotation);
	}

	void Tran::move(Vec const& translation)
	{
		this->acqPosition() += translation;
	}
	
	void Tran::locallyMove(Vec const& translation)
	{
		this->acqPosition() += this->getRotation() * translation;
	}

	void Tran::moveAlong(Vec const& axis, float distance)
	{
		this->acqPosition() += distance * axis;
	}

	void Tran::locallyMoveAlong(Vec const& axis, float distance)
	{
		this->acqPosition() += distance * (this->getRotation() * axis);
	}

	void Tran::rotate(Vec const& axis, float radians)
	{
		this->acqRotation() = Quats::Rotate(this->getRotation(), axis, radians);
	}

	void Tran::locallyRotate(Vec const& axis, float radians)
	{
		this->acqRotation() = Quats::LocallyRotate(this->getRotation(), axis, radians);
	}

	void Tran::lookTowards(Vec const& target, Vec const& up)
	{
		this->acqRotation() = Quats::LookTowards(this->getPosition(), target, up);
	}

	void Tran::_updatePositionDeps()
	{
		this->_cached_positionMatrix = glm::translate(IdentityMat, this->_position);
	}

	void Tran::_updateRotationDeps()
	{
		this->_cached_rotationMatrix = glm::mat4_cast(this->_rotation);
		this->_cached_forwardVec = glm::rotate(this->_rotation, Vecs::Forwards);
		this->_cached_upVec = glm::rotate(this->_rotation, Vecs::Up);
		this->_cached_rightVec = glm::rotate(this->_rotation, Vecs::Right);
	}
	
	void Tran::_updateScaleDeps()
	{
		this->_cached_scaleMatrix = glm::scale(IdentityMat, this->_scale);
	}
}

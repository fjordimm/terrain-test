
#pragma once

#include "Fjordimm3DEngine/(Form)/Form.hpp"

namespace Fjordimm3DEngine
{
	class PhysicForm : public Form
	{
		/* Constructors */

	   protected:
		PhysicForm() = delete;
		PhysicForm(const PhysicForm&) = delete;
		PhysicForm& operator=(const PhysicForm&) = delete;

		PhysicForm(WorldState& worldState);

	   protected:
		template <class T, typename std::enable_if<std::is_base_of<PhysicForm, T>::value>::type* = nullptr>
		static inline std::unique_ptr<T> New(WorldState& worldState)
		{ return Form::New<T>(worldState); }

	   public:
		static inline std::unique_ptr<PhysicForm> New(WorldState& worldState)
		{ return PhysicForm::New<PhysicForm>(worldState); }
		
		/* Fields */

	   public:
		Vec velocity;
		float friction;

		/* Methods */

	   protected:
		void onCreate_(WorldState& worldState) final;
		void onUpdate_(WorldState& worldState, float deltaTime) final;
		virtual void onCreate__(WorldState& worldState) {};
		virtual void onUpdate__(WorldState& worldState, float deltaTime) {};

		/* Friends */

		friend std::unique_ptr<PhysicForm> std::make_unique<PhysicForm>(Fjordimm3DEngine::WorldState&);
	};
}

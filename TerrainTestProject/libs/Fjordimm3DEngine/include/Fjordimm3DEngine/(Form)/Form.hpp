
#pragma once

#include <memory>
#include "Fjordimm3DEngine/(Util)/(Tran)/Tran.hpp"
#include "Fjordimm3DEngine/(Drawing)/FormDrawContent.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"
#include "Fjordimm3DEngine/(World)/WorldState.hpp"

namespace Fjordimm3DEngine
{
	class Form
	{
		/* Constructors */

	   protected:
		Form() = delete;
		Form(Form const&) = delete;
		Form& operator=(Form const&) = delete;
		
		Form(WorldState& worldState);
		
	   public:
		~Form();

	   protected:
		template <class T, typename std::enable_if<std::is_base_of<Form, T>::value>::type* = nullptr>
		static std::unique_ptr<T> New(WorldState& worldState)
		{
			std::unique_ptr<T> ret = std::make_unique<T>(worldState);
			ret->onCreate(worldState);
			return ret;
		}

	   public:
		static inline std::unique_ptr<Form> New(WorldState& worldState)
		{ return Form::New<Form>(worldState); }

		/* Fields */

	   public:
		Tran tran;

	   private:
		FormDrawContent formDrawContent;
		std::list<std::tuple<Mesh*, Tran*>>::const_iterator shaderProgramSpot;

		/* Methods */

	   public:
		void changeMesh(Mesh* mesh);
		void changeMaterialColor(Color materialColor);
		void changeTexture(Texture* texture);

	   private:
		void onCreate(WorldState& worldState);
	   public:
		void onUpdate(WorldState& worldState, float deltaTime);

	   protected:
		virtual void onCreate_(WorldState& worldState) {}
		virtual void onUpdate_(WorldState& worldState, float deltaTime) {}

		/* Friends */

		friend std::unique_ptr<Form> std::make_unique<Form>(Fjordimm3DEngine::WorldState&);

		// TODO: do ShaderProgram.removeForm() when Form is removed

		// TODO: call cleanupForGl() for each DrawObj
	};
}

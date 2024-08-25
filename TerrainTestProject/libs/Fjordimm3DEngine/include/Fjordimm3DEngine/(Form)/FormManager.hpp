
#pragma once

#include <unordered_map>
#include <memory>

namespace Fjordimm3DEngine
{
	// Forward declarations
	class Form;

	class FormManager
	{
		/* Constructors */

	   public:
		FormManager(FormManager const&) = delete;
		FormManager& operator=(FormManager const&) = delete;
		
		FormManager();
		
		/* Fields */

	   private:
		std::unordered_map<Form*, std::unique_ptr<Form>> formDict;

		/* Methods */

	   public:
		Form* add(std::unique_ptr<Form> form);
		void remove(Form* form);

		// To make it iterable:
		std::unordered_map<Form*, std::unique_ptr<Form>>::const_iterator begin();
		std::unordered_map<Form*, std::unique_ptr<Form>>::const_iterator end();
	};
}

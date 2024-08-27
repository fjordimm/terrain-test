
#pragma once

#include <unordered_map>
#include <memory>
#include <mutex>

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
		std::mutex mut_formDict;

		/* Methods */

	   public:
		template <typename T, typename std::enable_if<std::is_base_of<Form, T>::value>::type* = nullptr>
		T* add(std::unique_ptr<T> form)
		{
			std::lock_guard<std::mutex> _lock(this->mut_formDict);

			Form* ret = form.get();
			this->formDict[ret] = std::move(form);
			return dynamic_cast<T*>(ret);
		}
		
		void remove(Form* form);

		// To make it iterable:
		std::unordered_map<Form*, std::unique_ptr<Form>>::const_iterator begin();
		std::unordered_map<Form*, std::unique_ptr<Form>>::const_iterator end();
	};
}

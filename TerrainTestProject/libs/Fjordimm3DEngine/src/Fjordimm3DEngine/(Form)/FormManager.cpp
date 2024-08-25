
#include "Fjordimm3DEngine/(Form)/FormManager.hpp"

#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	FormManager::FormManager() :
		formDict()
	{}

	/* Methods */

	Form* FormManager::add(std::unique_ptr<Form> form)
	{
		Form* ret = form.get();
		this->formDict[ret] = std::move(form);
		return ret;
	}

	void FormManager::remove(Form* form)
	{
		auto tryGet = this->formDict.find(form);
		if (tryGet != this->formDict.end())
		{
			this->formDict.erase(tryGet);
		}
		else
		{
			Debug::LogNonfatalError("Tried to remove a form that isn't in the form manager.");
		}
	}

	std::unordered_map<Form*, std::unique_ptr<Form>>::const_iterator FormManager::begin()
	{
		return this->formDict.cbegin();
	}

	std::unordered_map<Form*, std::unique_ptr<Form>>::const_iterator FormManager::end()
	{
		return this->formDict.cend();
	}
}

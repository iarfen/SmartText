#include "dictionary_abbreviation.hpp"

using namespace std;

namespace smtext
{
	dictionary_abbreviation::dictionary_abbreviation() : dictionary_entry(),name()
	{
	}

	dictionary_abbreviation::dictionary_abbreviation(const string& new_name,const string& new_description,language new_language) : dictionary_entry(new_description,new_language),name(new_name)
	{
	}

	string dictionary_abbreviation::get_name() const
	{
		return name;
	}

	entry_type dictionary_abbreviation::get_entry_type() const
	{
		return entry_type::abbreviation;
	}
}

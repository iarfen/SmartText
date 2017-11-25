#include "dictionary_suffix.hpp"

using namespace std;

namespace smtext
{
	dictionary_suffix::dictionary_suffix() : dictionary_entry(),name()
	{
	}

	dictionary_suffix::dictionary_suffix(const string& new_name,const string& new_description,language new_language) : dictionary_entry(new_description,new_language),name(new_name)
	{
	}

	string dictionary_suffix::get_name() const
	{
		return name;
	}

	entry_type dictionary_suffix::get_entry_type() const
	{
		return entry_type::suffix;
	}
}

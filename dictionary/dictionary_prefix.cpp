#include "dictionary_prefix.hpp"

using namespace std;

namespace smtext
{
	dictionary_prefix::dictionary_prefix() : dictionary_entry(),name()
	{
	}

	dictionary_prefix::dictionary_prefix(const string& new_name,const string& new_description,language new_language) : dictionary_entry(new_description,new_language),name(new_name)
	{
	}

	string dictionary_prefix::get_name() const
	{
		return name;
	}

	entry_type dictionary_prefix::get_entry_type() const
	{
		return entry_type::prefix;
	}
}

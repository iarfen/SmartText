#include "dictionary/dictionary_entry.hpp"

using namespace std;

namespace smtext
{
	dictionary_entry::dictionary_entry() : description()
	{
	}

	dictionary_entry::dictionary_entry(const string& new_description,language new_language) : description(new_description,new_language)
	{
	}
}

ostream& operator << (ostream& os, const smtext::dictionary_entry& x)
{
	return os << x.get_name() << ": " << x.get_description();
}

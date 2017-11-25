#include "dictionary_word.hpp"

using namespace std;

namespace smtext
{
	dictionary_word::dictionary_word() : word(),dictionary_entry(),type(),common_word()
	{
	}

	dictionary_word::dictionary_word(const string& new_chars,const string& new_description,language new_language,word_type new_type,bool new_common_word) : word(new_chars),dictionary_entry(new_description,new_language),type(new_type),common_word(new_common_word)
	{
	}

	string dictionary_word::get_name() const
	{
		return word::get_chars();
	}

	entry_type dictionary_word::get_entry_type() const
	{
		return entry_type::word;
	}
}

ostream& operator << (ostream& os, const smtext::dictionary_word& x)
{
	return os << x.get_name() << "(" << smtext::to_string(x.get_type()) << "): " << x.get_description();
}

#include "adjective_word.hpp"

using namespace std;

namespace smtext
{
	adjective_word::adjective_word() : dictionary_word(),plural()
	{
	}

	adjective_word::adjective_word(const string& new_chars,const string& new_plural,const string& new_description,language new_language,word_type new_type) : dictionary_word(new_chars,new_description,new_language,new_type),plural(new_plural)
	{
	}
}

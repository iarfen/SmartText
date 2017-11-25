#include "verb_word.hpp"

using namespace std;

namespace smtext
{
	verb_word::verb_word() : dictionary_word()
	{
	}

	verb_word::verb_word(const string& new_chars,const string& new_description,language new_language,word_type new_type) : dictionary_word(new_chars,new_description,new_language,new_type)
	{
	}
}

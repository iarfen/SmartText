#include "dictionary/dictionary_term.hpp"
#include "word.hpp"

#include <sstream>

#include "boost/algorithm/string.hpp"

using namespace std;

namespace smtext
{
	dictionary_term::dictionary_term() : dictionary_entry(),name_words(),plural_name_words()
	{
	}

	dictionary_term::dictionary_term(const string& new_name_words,const string& new_plural_name_words,const string& new_description,language new_language) : dictionary_entry(new_description,new_language),name_words(),plural_name_words()
	{
		vector<string> new_name_words_string;
		boost::split(new_name_words_string,new_name_words,boost::is_any_of(" "));
		for (const string& new_name_word : new_name_words_string)
		{
			word name_word (new_name_word);
			name_words.push_back(name_word);
		}
		vector<string> new_plural_name_words_string;
		boost::split(new_plural_name_words_string,new_plural_name_words,boost::is_any_of(" "));
		for (const string& new_plural_word : new_plural_name_words_string)
		{
			word plural_word (new_plural_word);
			plural_name_words.push_back(plural_word);
		}
	}

	string dictionary_term::get_name() const
	{
		ostringstream out;
		for (unsigned int i = 0; i < name_words.size(); i++)
		{
			out << name_words[i];
			if ((i + 1) < name_words.size())
			{
				out << " ";
			}
		}
		return out.str();
	}

	entry_type dictionary_term::get_entry_type() const
	{
		return entry_type::term;
	}
}

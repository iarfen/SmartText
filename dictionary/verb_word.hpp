#ifndef SMTEXT_DICTIONNARY_VERB_WORD_HPP_INCLUDED
#define SMTEXT_DICTIONNARY_VERB_WORD_HPP_INCLUDED

#include "dictionary_word.hpp"

using namespace std;

namespace smtext
{
	class verb_word : public dictionary_word
	{
		public:
			verb_word();
			explicit verb_word(const string&,const string&,language,word_type);
	};
}

#endif // SMTEXT_DICTIONNARY_VERB_WORD_HPP_INCLUDED

#ifndef SMTEXT_DICTIONNARY_DICTIONNNARY_WORD_HPP_INCLUDED
#define SMTEXT_DICTIONNARY_DICTIONNNARY_WORD_HPP_INCLUDED

#include "dictionary_entry.hpp"
#include "language.hpp"
#include "text.hpp"
#include "word.hpp"
#include "grammar/basic_grammar.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace smtext
{
	class dictionary_word : public word, public dictionary_entry
	{
		public:
			dictionary_word();
			explicit dictionary_word(const string&,const string&,language,word_type,bool = false);

			inline word_type& get_type()
			{
				return type;
			}

			inline const word_type& get_type() const
			{
				return type;
			}

			inline bool& is_common_word()
			{
				return common_word;
			}

			inline const bool& is_common_word() const
			{
				return common_word;
			}

			virtual string get_name() const;
			virtual entry_type get_entry_type() const;

		private:
			word_type type;
			bool common_word;
	};
}

ostream& operator << (ostream&, const smtext::dictionary_word&);

#endif // SMTEXT_DICTIONNARY_DICTIONNNARY_WORD_HPP_INCLUDED

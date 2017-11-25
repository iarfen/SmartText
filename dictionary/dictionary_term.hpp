#ifndef SMARTTEXT_DICTIONNARY_DICTIONNARY_TERM_HPP_INCLUDED
#define SMARTTEXT_DICTIONNARY_DICTIONNARY_TERM_HPP_INCLUDED

#include "dictionary_entry.hpp"
#include "language.hpp"
#include "word.hpp"

#include <string>
#include <vector>

using namespace std;

namespace smtext
{
	class dictionary_term : public dictionary_entry
	{
		public:
			dictionary_term();
			explicit dictionary_term(const string&,const string&,const string&,language);

			inline vector<word>& get_name_words()
			{
				return name_words;
			}

			inline const vector<word>& get_name_words() const
			{
				return name_words;
			}

			inline vector<word>& get_plural_name_words()
			{
				return plural_name_words;
			}

			inline const vector<word>& get_plural_name_words() const
			{
				return plural_name_words;
			}

			virtual string get_name() const;
			virtual entry_type get_entry_type() const;

		private:
			vector<word> name_words;
			vector<word> plural_name_words;
	};
}

#endif // SMARTTEXT_DICTIONNARY_DICTIONNARY_TERM_HPP_INCLUDED

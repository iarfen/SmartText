#ifndef SMTEXT_DICTIONNARY_SUSTANTIVE_WORD_HPP_INCLUDED
#define SMTEXT_DICTIONNARY_SUSTANTIVE_WORD_HPP_INCLUDED

#include "dictionary_word.hpp"

using namespace std;

namespace smtext
{
	class sustantive_word : public dictionary_word
	{
		public:
			sustantive_word();
			explicit sustantive_word(const string&,const string&,const string&,language,word_type);

			inline string& get_plural()
			{
				return plural;
			}

			inline const string& get_plural() const
			{
				return plural;
			}

		private:
			string plural;
	};
}

#endif // SMTEXT_DICTIONNARY_SUSTANTIVE_WORD_HPP_INCLUDED

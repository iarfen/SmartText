#ifndef SMTEXT_DICTIONNARY_ADJECTIVE_WORD_HPP_INCLUDED
#define SMTEXT_DICTIONNARY_ADJECTIVE_WORD_HPP_INCLUDED

#include "dictionary_word.hpp"

#include <string>

using namespace std;

namespace smtext
{
	class adjective_word : public dictionary_word
	{
		public:
			adjective_word();
			explicit adjective_word(const string&,const string&,const string&,language,word_type);

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

#endif // SMTEXT_DICTIONNARY_ADJECTIVE_WORD_HPP_INCLUDED

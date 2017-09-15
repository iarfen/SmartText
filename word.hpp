#ifndef WORD_HPP_INCLUDED
#define WORD_HPP_INCLUDED

#include <iostream>
#include <map>
#include <string>

using namespace std;

namespace smarttext
{
	extern map<string,string> common_chat_conversions;

	class word
	{
		public:
			word(string);

			inline const string& get_chars() const
			{
				return chars;
			}

			wstring display() const;

			bool is_language_word() const;
			bool is_chat_word() const;
			bool is_lowercase() const;

			inline bool is_uppercase() const
			{
				return !is_lowercase();
			}

			bool is_capitalized() const;

			inline bool is_incorrect_word() const
			{
				return !is_chat_word();
			}

		private:
			string chars;
	};
}

wostream& operator <<(wostream&, const smarttext::word&);

#endif // WORD_HPP_INCLUDED

#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED

#include "language.hpp"
#include "word.hpp"

#include <string>
#include <vector>

using namespace std;

namespace smarttext
{
	class line
	{
		public:
			line(string,language);

			inline const vector<word>& get_words() const
			{
				return words;
			}

			inline char get_start_punctuation() const
			{
				return start_punctuation;
			}

			inline char get_final_punctuation() const
			{
				return final_punctuation;
			}

		private:
			vector<word> words;
			char start_punctuation;
			char final_punctuation;
	};
}

#endif // LINE_HPP_INCLUDED

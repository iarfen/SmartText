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

			/// Returns a vector<word> of the words that compose the line
			inline const vector<word>& get_words() const
			{
				return words;
			}

			/// Returns the starting character punctuation, if any
			inline char get_start_punctuation() const
			{
				return start_punctuation;
			}

			/// Returns the final character punctuation, if any
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

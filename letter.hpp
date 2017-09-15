#ifndef LETTER_HPP_INCLUDED
#define LETTER_HPP_INCLUDED

#include "language.hpp"

using namespace std;

namespace smarttext
{
	bool is_punctuation(char,language);
	bool is_starting_punctuation(char,language);
	bool is_ending_punctuation(char,language);
	bool is_middle_punctuation(char,language);
}

#endif // LETTER_HPP_INCLUDED

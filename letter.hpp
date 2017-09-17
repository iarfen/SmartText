#ifndef LETTER_HPP_INCLUDED
#define LETTER_HPP_INCLUDED

#include "language.hpp"

using namespace std;

namespace smarttext
{
	/// \brief Returns true if the character is a punctuation for the given language
	/// \param x punctuation character to test
	/// \param current_language language of the text the punctuation character is on
	bool is_punctuation(char,language);

	/// \brief Returns true if the character is a starting punctuation for the given language
	/// \param x punctuation character to test
	/// \param current_language language of the text the punctuation character is on
	bool is_starting_punctuation(char,language);

	/// \brief Returns true if the character is an ending punctuation for the given language
	/// \param x punctuation character to test
	/// \param current_language language of the text the punctuation character is on
	bool is_ending_punctuation(char,language);

	/// \brief Returns true if the character is a middle punctuation for the given language
	/// \param x punctuation character to test
	/// \param current_language language of the text the punctuation character is on
	bool is_middle_punctuation(char,language);
}

#endif // LETTER_HPP_INCLUDED

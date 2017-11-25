#ifndef SMTEXT_GRAMMAR_BASIC_GRAMMAR_HPP_INCLUDED
#define SMTEXT_GRAMMAR_BASIC_GRAMMAR_HPP_INCLUDED

#include <string>

using namespace std;

namespace smtext
{
	enum class word_type {adjective,sustantive,verb};

	string to_string(word_type);
}

#endif // SMTEXT_GRAMMAR_BASIC_GRAMMAR_HPP_INCLUDED

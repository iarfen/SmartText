#include "basic_grammar.hpp"

using namespace std;

namespace smtext
{
	string to_string(word_type type)
	{
		if (type == word_type::adjective)
		{
			return "adjective";
		}
		else if (type == word_type::sustantive)
		{
			return "sustantive";
		}
		else if (type == word_type::verb)
		{
			return "verb";
		}
	}
}

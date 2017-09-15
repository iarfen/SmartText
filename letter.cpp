#include "language.hpp"
#include "letter.hpp"

using namespace std;

namespace smarttext
{
	/// Returns true if the character is a punctuation for the given language
	bool is_punctuation(char x,language current_language)
	{
		if (current_language == language::spanish)
		{
			return is_starting_punctuation(x,current_language) or is_middle_punctuation(x,current_language) or is_ending_punctuation(x,current_language);
		}
		else if (current_language == language::english)
		{
			return is_starting_punctuation(x,current_language) or is_middle_punctuation(x,current_language) or is_ending_punctuation(x,current_language);
		}
		return false;
	}

	/// Returns true if the character is a starting punctuation for the given language
	bool is_starting_punctuation(char x,language current_language)
	{
		if (current_language == language::spanish)
		{
			return (x == '¡' or x == '¿' or x == '-');
		}
		else if (current_language == language::english)
		{
			return false;
		}
		return false;
	}

	/// Returns true if the character is an ending punctuation for the given language
	bool is_ending_punctuation(char x,language current_language)
	{
		if (current_language == language::spanish)
		{
			return (x == '.' or x == '!' or x == '?' or x == ':');
		}
		else if (current_language == language::english)
		{
			return (x == '.' or x == '!' or x == '?' or x == ':');
		}
		return false;
	}

	/// Returns true if the character is a middle punctuation for the given language
	bool is_middle_punctuation(char x,language current_language)
	{
		if (current_language == language::spanish)
		{
			return (x == ',' or x == '(' or x == ')' or x == '[' or x == ']' or x == '"' or x == '\'' or x == ';' or x == '-');
		}
		else if (current_language == language::english)
		{
			return (x == ',' or x == '(' or x == ')' or x == '[' or x == ']' or x == '"' or x == '\'' or x == ';' or x == '-');
		}
		return false;
	}
}

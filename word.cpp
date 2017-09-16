#include "word.hpp"

#include "boost/algorithm/string.hpp"

#include <cctype>

using namespace std;

namespace smarttext
{
	map<string,string> common_chat_conversions
	{
		{"€","e"},
		{"0","o"},
		{"y","i"},
		{"z","s"},
		{"k","c"},
		{"b","v"},
		{"v","b"},
		{"w","gu"},
		{"sh","ch"},
		{"zh","ch"},
		{"r","rr"}
	};

	/// Constructs a new word with the given characters
	word::word(string new_chars) : chars(new_chars)
	{
	}

	/// Returns a wstring containing the word
	wstring word::display() const
	{
		wstring chars2 (chars.length(),L' ');
		copy(chars.begin(),chars.end(),chars2.begin());
		return chars2;
	}

	/// Returns true if the word is a number
	bool word::is_number() const
	{
		for (const char& word_char : chars)
		{
			if (!isdigit(word_char))
			{
				return false;
			}
		}
		return true;
	}

	/// Returns true if the word is composed by letters and not by numbers
	bool word::is_letter_word() const
	{
		for (const char& word_char : chars)
		{
			if (!isalpha(word_char))
			{
				return false;
			}
		}
		return true;
	}

	/// Returns true if the word is composed only by characters of the language
	bool word::is_language_word() const
	{
		return (is_letter_word() or is_number());
	}

	/// Returns true if the word is a normal word related to the rules of the language, or a chat word with common characters switched
	bool word::is_chat_word() const
	{
		for (const char& word_char : chars)
		{
			if (!isalpha(word_char) and word_char != '0' and word_char != '€')
			{
				return false;
			}
		}
		return true;
	}

	/// Returns true if all the characters of the word are lowercase
	bool word::is_lowercase() const
	{
		for (const char& word_char : chars)
		{
			if (!islower(word_char))
			{
				return false;
			}
		}
		return true;
	}

	/// Returns true if the first character is capitalized and all the others are lowercase
	bool word::is_capitalized() const
	{
		if (!isupper(chars[0]))
		{
			return false;
		}
		for (const char& word_char : chars)
		{
			if (!islower(word_char))
			{
				return false;
			}
		}
		return true;
	}

	/// Returns true if the word is a day
	bool word::is_day(language current_language) const
	{
		if (current_language == language::english)
		{
			return (chars == "monday" or chars == "thursday" or chars == "wednesday" or chars == "tuesday" or chars == "friday" or chars == "saturday" or chars == "sunday");
		}
		else if (current_language == language::spanish)
		{
			return (chars == "lunes" or chars == "martes" or chars == "miércoles" or chars == "jueves" or chars == "viernes" or chars == "sábado" or chars == "domingo");
		}
		return false;
	}

	/// Returns true if the word is a month
	bool word::is_month(language current_language) const
	{
		if (current_language == language::english)
		{
			return (chars == "january" or chars == "february" or chars == "march" or chars == "april" or chars == "may" or chars == "june" or chars == "july" or chars == "august" or chars == "september" or chars == "october" or chars == "november" or chars == "december");
		}
		else if (current_language == language::spanish)
		{
			return (chars == "enero" or chars == "febrero" or chars == "marzo" or chars == "abril" or chars == "mayo" or chars == "junio" or chars == "julio" or chars == "agosto" or chars == "septiembre" or chars == "octubre" or chars == "noviembre" or chars == "diciembre");
		}
		return false;
	}
}

/// Outputs the word to a wostream buffer
wostream& operator <<(wostream& os, const smarttext::word& x)
{
	return os << x.display();
}

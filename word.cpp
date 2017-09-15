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

	/// Returns true if the word is composed only by characters of the language
	bool word::is_language_word() const
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
}

/// Outputs the word to a wostream buffer
wostream& operator <<(wostream& os, const smarttext::word& x)
{
	return os << x.display();
}

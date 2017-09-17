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

	word::word(string new_chars) : chars(new_chars)
	{
	}

	wstring word::display() const
	{
		wstring chars2 (chars.length(),L' ');
		copy(chars.begin(),chars.end(),chars2.begin());
		return chars2;
	}

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

	bool word::is_language_word() const
	{
		return (is_letter_word() or is_number());
	}

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

	bool word::is_insult(language current_language) const
	{
		if (current_language == language::spanish)
		{
			return (chars == "imbécil" or chars == "imbécila" or chars == "estúpido" or chars == "estúpida" or chars == "tonto" or chars == "tonta" or chars == "weon" or chars == "weona" or chars == "wn" or chars == "wna" or chars == "patudo" or chars == "patuda" or chars == "patuo" or chars == "patua" or chars == "sinvergüenza" or chars == "culiado" or chars == "culiada" or chars == "culiao" or chars == "culiaa" or chars == "ql" or chars == "qliao" or chars == "qliaa" or chars == "qliado" or chars == "qliada" or chars == "flaite" or chars == "cochino" or chars == "cochina" or chars == "chancho" or chars == "chancha" or chars == "cerdo" or chars == "cerda" or chars == "mierda" or chars == "pto" or chars == "pta" or chars == "puto" or chars == "puta" or chars == "prostituto" or chars == "prostituta" or chars == "gigolo" or chars == "maricón" or chars == "maricona" or chars == "maraco" or chars == "maraca" or chars == "mamón" or chars == "mamona" or chars == "concha" or chars == "ctm" or chars == "conchatumare" or chars == "hueco" or chars == "hueca" or chars == "mugre");
		}
	}
}

bool operator ==(string x, const smarttext::word& y)
{
	return (x == y.get_chars());
}

bool operator ==(const smarttext::word& x,string y)
{
	return (x.get_chars() == y);
}

bool operator ==(const smarttext::word& x,const smarttext::word& y)
{
	return (x.get_chars() == y.get_chars());
}

wostream& operator <<(wostream& os, const smarttext::word& x)
{
	return os << x.display();
}

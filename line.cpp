#include "letter.hpp"
#include "line.hpp"
#include "text.hpp"

#include "boost/algorithm/string.hpp"

#include <iostream>

using namespace std;

namespace smarttext
{
	line::line(string new_line,const text* new_text) : words(),start_punctuation('\0'),final_punctuation('\0'),raw_content(new_line),text_container(new_text)
	{
		string final_words;
		if (is_starting_punctuation(new_line[0],text_container->get_current_language()))
		{
			if (is_ending_punctuation(new_line[new_line.size() - 1],text_container->get_current_language()))
			{
				final_words = new_line.substr(1,new_line.size() - 2);
				start_punctuation = new_line[0];
				final_punctuation = new_line[new_line.size() - 1];
			}
			else
			{
				final_words = new_line.substr(1,new_line.size() - 1);
				start_punctuation = new_line[0];
			}
		}
		else
		{
			if (is_ending_punctuation(new_line[new_line.size() - 1],text_container->get_current_language()))
			{
				final_words = new_line.substr(0,new_line.size() - 1);
				final_punctuation = new_line[new_line.size() - 1];
			}
			else
			{
				final_words = new_line;
			}
		}
		vector<string> new_words;
		boost::split(new_words,final_words,boost::is_any_of(" ,"));
		for (const string& new_word : new_words)
		{
			word final_word (new_word);
			words.push_back(final_word);
		}
	}

	wstring line::display() const
	{
		wstring raw_content2 (raw_content.length(),L' ');
		copy(raw_content.begin(),raw_content.end(),raw_content2.begin());
		return raw_content2;
	}

	bool line::has_partial_date() const
	{
		language current_language = text_container->get_current_language();
		for (const word& line_word : words)
		{
			if (line_word.is_month(current_language) or line_word.is_day(current_language))
			{
				return true;
			}
		}
	}

	bool line::has_date() const
	{
		language current_language = text_container->get_current_language();
		for (const word& line_word : words)
		{
			if (line_word.is_month(current_language) or line_word.is_day(current_language))
			{
				return true;
			}
		}
	}
}

wostream& operator <<(wostream& os, const smarttext::line& x)
{
	return os << x.display();
}

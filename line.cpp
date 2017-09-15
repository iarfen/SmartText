#include "letter.hpp"
#include "line.hpp"

#include "boost/algorithm/string.hpp"

#include <iostream>

using namespace std;

namespace smarttext
{
	line::line(string new_line,language current_language) : words(),start_punctuation('\0'),final_punctuation('\0')
	{
		string final_words;
		if (is_starting_punctuation(new_line[0],current_language))
		{
			if (is_ending_punctuation(new_line[new_line.size() - 1],current_language))
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
			if (is_ending_punctuation(new_line[new_line.size() - 1],current_language))
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
}

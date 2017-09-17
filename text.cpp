#include "text.hpp"

#include "boost/algorithm/string.hpp"

using namespace std;

namespace smarttext
{
	text::text(string text_content, language new_current_language) : paragraphs(),current_language(new_current_language),raw_content(text_content)
	{
		vector<string> new_paragraphs;
		boost::split(new_paragraphs,text_content,boost::is_any_of("\n"));
		for (const string& new_paragraph : new_paragraphs)
		{
			if (new_paragraph != "")
			{
				paragraph final_paragraph (new_paragraph,this);
				paragraphs.push_back(final_paragraph);
			}
		}
	}

	wstring text::display() const
	{
		wstring raw_content2 (raw_content.length(),L' ');
		copy(raw_content.begin(),raw_content.end(),raw_content2.begin());
		return raw_content2;
	}

	vector<word> text::get_words() const
	{
		vector<word> out_words;
		for (const paragraph& text_paragraph : paragraphs)
		{
			for (const line& text_line : text_paragraph.get_lines())
			{
				for (const word& text_word : text_line.get_words())
				{
					out_words.push_back(text_word);
				}
			}
		}
		return out_words;
	}

	vector<line> text::get_lines() const
	{
		vector<line> out_lines;
		for (const paragraph& text_paragraph : paragraphs)
		{
			for (const line& text_line : text_paragraph.get_lines())
			{
				out_lines.push_back(text_line);
			}
		}
		return out_lines;
	}

	bool text::has_word(string x) const
	{
		vector<word> text_words;
		for (const word& text_word : text_words)
		{
			if (text_word == x)
			{
				return true;
			}
		}
		return false;
	}
}

wostream& operator <<(wostream& os, const smarttext::text& x)
{
	return os << x.display();
}

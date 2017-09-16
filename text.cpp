#include "text.hpp"

#include "boost/algorithm/string.hpp"

using namespace std;

namespace smarttext
{
	text::text(string text_content, language new_current_language) : paragraphs(),current_language(new_current_language),raw_content(text_content)
	{
		vector<string> new_paragraphs;
		boost::split(new_paragraphs,text_content,boost::is_any_of(".:?!"));
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
}

wostream& operator <<(wostream& os, const smarttext::text& x)
{
	return os << x.display();
}

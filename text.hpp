#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED

#include "paragraph.hpp"

#include <string>
#include <vector>

using namespace std;

namespace smarttext
{
	/// \class text
	/// \brief The text class represents an amount of text, composed of any amount of paragraphs, of any kind. It can be specialized in more specific kinds of text, like chapters, books, blog notes, etc.
	class text
	{
		public:
			/// \brief Create a new text of the given string and the selected language
			/// \param text_content characters of the text
			/// \param new_current_language language the text is on
			explicit text(string,language);

			/// Returns the paragraphs of the text
			inline const vector<paragraph>& get_paragraphs() const
			{
				return paragraphs;
			}

			/// Returns the selected language
			inline language get_current_language() const
			{
				return current_language;
			}

			/// Returns a wstring containing the text
			wstring display() const;

		private:
			vector<paragraph> paragraphs;
			language current_language;
			string raw_content;
	};
}

/// Outputs the text to a wostream buffer
wostream& operator <<(wostream&, const smarttext::text&);

#endif // TEXT_HPP_INCLUDED

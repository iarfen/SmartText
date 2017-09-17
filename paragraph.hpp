#ifndef PARAGRAPH_HPP_INCLUDED
#define PARAGRAPH_HPP_INCLUDED

#include "line.hpp"

#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace smarttext
{
	/// \class paragraph
	/// \brief The paragraph class represents a paragraph of text. It distinguish each line that the paragraph has
	class paragraph
	{
		public:
			/// \brief Creates a new paragraph of the given string
			/// \param paragraph_content text of the paragraph
			/// \param new_content_language language of the paragraph
			explicit paragraph(string,const text*);

			/// \brief Returns the lines of the paragraph
			inline const vector<line>& get_lines() const
			{
				return lines;
			}

			/// \brief Returns a wstring containing the paragraph
			wstring display() const;

		private:
			vector<line> lines;
			string raw_content;
			const text* text_container;
	};
}

/// \brief Outputs the paragraph to a wostream buffer
wostream& operator <<(wostream&, const smarttext::paragraph&);

#endif // PARAGRAPH_HPP_INCLUDED

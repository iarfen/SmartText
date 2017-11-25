#ifndef PARAGRAPH_HPP_INCLUDED
#define PARAGRAPH_HPP_INCLUDED

#include "line.hpp"

#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace smtext
{
	/// \class paragraph
	/// \brief The paragraph class represents a paragraph of text. It distinguish each line that the paragraph has
	class paragraph
	{
		public:
			/// \brief Default constructor. Constructs an empty paragraph
			paragraph();

			/// \brief Creates a new paragraph of the given string
			/// \param paragraph_content text of the paragraph
			/// \param new_content_language language of the paragraph
			explicit paragraph(const string&,const text*);

			/// \brief Returns the lines of the paragraph
			inline const vector<line>& get_lines() const
			{
				return lines;
			}

			/// \brief Returns a string containing the paragraph
			string display() const;

			/// \brief Returns all the words the paragraph is composed of
			vector<word> get_words() const;

			/// \brief Returns true if the paragraph has the word asked
			/// \param x string to compare the words to
			bool has_word(string) const;

			/// \brief Returns true if the paragraph has any of the words asked
			/// \param x vector of strings of the words to test
			bool has_any_word(vector<string>) const;

			/// \brief Returns true if the paragraph has all the words given
			/// \param x vector of strings of the words to test
			bool has_words(vector<string>) const;

			/// \brief Returns the number of words the paragraph has
			inline int number_of_words() const
			{
				return get_words().size();
			}

			/// \brief Returns the number of lines the paragraph has
			inline int number_of_lines() const
			{
				return lines.size();
			}

		private:
			vector<line> lines; ///< lines of the paragraph
			string raw_content; ///< original string of the paragraph
			const text* text_container; ///< parent text class of the paragraph class
	};
}

/// \brief Returns true if the paragraph is identical to the compared paragraph
bool operator ==(const smtext::paragraph&,const smtext::paragraph&);

/// \brief Outputs the paragraph to a ostream buffer
ostream& operator <<(ostream&, const smtext::paragraph&);

#endif // PARAGRAPH_HPP_INCLUDED

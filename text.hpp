#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED

#include "paragraph.hpp"

#include <string>
#include <vector>

using namespace std;

namespace smtext
{
	/// \class text
	/// \brief The text class represents an amount of text, composed of any amount of paragraphs, of any kind. It can be specialized in more specific kinds of text, like chapters, books, blog notes, etc.
	class text
	{
		public:
			/// \brief Create a new default text empty
			text();

			/// \brief Create a new text of the given string and the selected language
			/// \param text_content characters of the text
			/// \param new_current_language language the text is on
			explicit text(const string&,language);

			/// \brief Returns the paragraphs of the text
			inline vector<paragraph>& get_paragraphs()
			{
				return paragraphs;
			}

			/// \brief Returns the paragraphs of the text
			inline const vector<paragraph>& get_paragraphs() const
			{
				return paragraphs;
			}

			/// \brief Returns the selected language
			inline language& get_current_language()
			{
				return current_language;
			}

			/// \brief Returns the selected language
			inline const language& get_current_language() const
			{
				return current_language;
			}

			/// \brief Returns a string containing the text
			string display() const;

			/// \brief Returns all the words the text is composed of
			vector<word> get_words() const;

			/// \brief Returns all the lines the text is composed of
			vector<line> get_lines() const;

			/// \brief Returns true if the text has the word asked
			/// \param x string of the word to search
			bool has_word(const string&) const;

			/// \brief Returns true if the text has any of the words asked
			/// \param x vector of strings of the words to search
			bool has_any_word(const vector<string>&) const;

			/// \brief Returns true if the text has all the words asked
			/// \param x vector of strings of the words to search
			bool has_words(const vector<string>&) const;

			/// \brief Returns true if the text has the word sequence asked
			/// \param x string of the word sequence to search
			bool has_word_sequence(const string&) const;

			/// \brief Returns true if the text has the any of the word sequences asked
			/// \param x vector of strings of the words to search
			bool has_any_word_sequence(const vector<string>&) const;

			/// \brief Returns true if the text has all the word sequences asked
			/// \param x vector of strings of the words to search
			bool has_word_sequences(const vector<string>&) const;

			/// \brief Returns the number of words the text has
			inline int number_of_words() const
			{
				return get_words().size();
			}

			/// \brief Returns the number of lines the text has
			inline int number_of_lines() const
			{
				return get_lines().size();
			}

			/// \brief Returns the number of paragraphs the text has
			inline int number_of_paragraphs() const
			{
				return paragraphs.size();
			}

		private:
			vector<paragraph> paragraphs; ///< paragraphs of the text
			language current_language; ///< language the text is on
			string raw_content; ///< original string of the text
	};
}

/// \brief Returns true if the text is identical to the compared text
bool operator ==(const smtext::text&,const smtext::text&);

/// \brief Outputs the text to a ostream buffer
ostream& operator <<(ostream&, const smtext::text&);

#endif // TEXT_HPP_INCLUDED

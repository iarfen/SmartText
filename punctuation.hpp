#ifndef PUNCTUATION_HPP_INCLUDED
#define PUNCTUATION_HPP_INCLUDED

#include <string>

using namespace std;

namespace smarttext
{
	/// \class punctuation
	/// \brief class punctuation is used to work with all the punctuation inside the text. Each instance of this class represents a single punctuation.
	class punctuation
	{
		public:
			/// \brief Creates a new punctuation with the given characters
			/// \param new_chars characters of the punctuation
			explicit punctuation(string);

			/// \brief Returns the chars of the punctuation
			inline const string& get_chars() const
			{
				return chars;
			}

			/// \brief Returns a wstring containing the punctuation
			wstring display() const;

		private:
			/// \var string chars
			string chars;
	};
}

/// \brief Outputs the punctuation to a wostream buffer
wostream& operator <<(wostream&, const smarttext::punctuation&);

#endif // PUNCTUATION_HPP_INCLUDED

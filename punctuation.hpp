#ifndef PUNCTUATION_HPP_INCLUDED
#define PUNCTUATION_HPP_INCLUDED

#include <string>

using namespace std;

namespace smtext
{
	/// \class punctuation
	/// \brief class punctuation is used to work with all the punctuation inside the text. Each instance of this class represents a single punctuation.
	class punctuation
	{
		public:
			/// \brief Default constructor. Constructs an empty punctuation
			punctuation();

			/// \brief Creates a new punctuation with the given characters
			/// \param new_chars characters of the punctuation
			explicit punctuation(const string&);

			/// \brief Returns the chars of the punctuation
			inline const string& get_chars() const
			{
				return chars;
			}

			/// \brief Returns a string containing the punctuation
			string display() const;

		private:
			string chars; ///< characters that create the punctuation
	};
}

/// \brief Returns true if the punctuation is identical to the compared punctuation
bool operator ==(const smtext::punctuation&,const smtext::punctuation&);

/// \brief Outputs the punctuation to a ostream buffer
ostream& operator <<(ostream&, const smtext::punctuation&);

#endif // PUNCTUATION_HPP_INCLUDED

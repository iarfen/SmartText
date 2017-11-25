#ifndef LANGUAGE_HPP_INCLUDED
#define LANGUAGE_HPP_INCLUDED

#include <string>

using namespace std;

namespace smtext
{
	/// \enum enum class used to distinguish among different languages
	enum class language {spanish,english};

	/// \brief Returns the language value related to the language iso given
	/// \param iso string of the iso of the language to get
	language get_language_from_iso(const string&);

	/// \brief Returns if the given string represents an ISO or doesn't
	/// \param iso string of the iso of the language to test
	bool is_iso(const string&);
}

#endif // LANGUAGE_HPP_INCLUDED

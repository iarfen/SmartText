#ifndef LANGUAGE_HPP_INCLUDED
#define LANGUAGE_HPP_INCLUDED

#include <string>

using namespace std;

namespace smarttext
{
	/// \enum enum class used to distinguish among different languages
	enum class language {spanish,english};

	/// \brief Returns the language value related to the language iso given
	/// \param iso string of the iso of the language to get
	language get_language_from_iso(string);
}

#endif // LANGUAGE_HPP_INCLUDED

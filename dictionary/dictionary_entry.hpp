#ifndef SMARTTEXT_DICTIONNARY_DICTIONNARY_ENTRY_HPP_INCLUDED
#define SMARTTEXT_DICTIONNARY_DICTIONNARY_ENTRY_HPP_INCLUDED

#include "language.hpp"
#include "text.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace smtext
{
	enum class entry_type {word,term,prefix,suffix,abbreviation};

	class dictionary_entry
	{
		public:
			dictionary_entry();
			explicit dictionary_entry(const string&,language);

			inline text& get_description()
			{
				return description;
			}

			inline const text& get_description() const
			{
				return description;
			}

			inline language& get_language()
			{
				return description.get_current_language();
			}

			inline const language& get_language() const
			{
				return description.get_current_language();
			}

			virtual string get_name() const = 0;
			virtual entry_type get_entry_type() const = 0;

		private:
			text description;
	};
}

ostream& operator << (ostream&, const smtext::dictionary_entry&);

#endif // SMARTTEXT_DICTIONNARY_DICTIONNARY_ENTRY_HPP_INCLUDED

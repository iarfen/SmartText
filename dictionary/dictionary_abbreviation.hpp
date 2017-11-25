#ifndef SMARTTEXT_DICTIONNARY_DICTIONNARY_ABBREVIATION_HPP_INCLUDED
#define SMARTTEXT_DICTIONNARY_DICTIONNARY_ABBREVIATION_HPP_INCLUDED

#include "dictionary_entry.hpp"

#include <string>

using namespace std;

namespace smtext
{
	class dictionary_abbreviation : public dictionary_entry
	{
		public:
			dictionary_abbreviation();
			explicit dictionary_abbreviation(const string&,const string&,language);

			virtual string get_name() const;
			virtual entry_type get_entry_type() const;

		private:
			string name;
	};
}

#endif // SMARTTEXT_DICTIONNARY_DICTIONNARY_ABBREVIATION_HPP_INCLUDED

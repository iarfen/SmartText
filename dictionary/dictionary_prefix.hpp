#ifndef SMARTTEXT_DICTIONNARY_DICTIONNARY_PREFIX_HPP_INCLUDED
#define SMARTTEXT_DICTIONNARY_DICTIONNARY_PREFIX_HPP_INCLUDED

#include "dictionary_entry.hpp"
#include "language.hpp"

#include <string>

using namespace std;

namespace smtext
{
	class dictionary_prefix : public dictionary_entry
	{
		public:
			dictionary_prefix();
			explicit dictionary_prefix(const string&,const string&,language);

			virtual string get_name() const;
			virtual entry_type get_entry_type() const;

		private:
			string name;
	};
}

#endif // SMARTTEXT_DICTIONNARY_DICTIONNARY_PREFIX_HPP_INCLUDED

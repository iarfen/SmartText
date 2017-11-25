#ifndef SMARTTEXT_DICTIONNARY_DICTIONNARY_SUFFIX_HPP_INCLUDED
#define SMARTTEXT_DICTIONNARY_DICTIONNARY_SUFFIX_HPP_INCLUDED

#include "dictionary_entry.hpp"

#include <string>

using namespace std;

namespace smtext
{
	class dictionary_suffix : public dictionary_entry
	{
		public:
			dictionary_suffix();
			explicit dictionary_suffix(const string&,const string&,language);

			virtual string get_name() const;
			virtual entry_type get_entry_type() const;

		private:
			string name;
	};
}

#endif // SMARTTEXT_DICTIONNARY_DICTIONNARY_SUFFIX_HPP_INCLUDED

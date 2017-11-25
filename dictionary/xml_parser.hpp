#ifndef SMTEXT_DICTIONNARY_XML_PARSER_HPP_INCLUDED
#define SMTEXT_DICTIONNARY_XML_PARSER_HPP_INCLUDED

#include "dictionary_entry.hpp"

#include <memory>
#include <string>
#include <vector>

using namespace std;

namespace smtext
{
	vector<shared_ptr<dictionary_entry>> create_words_from_dictionary_file(const string&);
	string validate_dictionary_file(const string&);
}

#endif // SMTEXT_DICTIONNARY_XML_PARSER_HPP_INCLUDED

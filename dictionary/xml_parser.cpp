#include "xml_parser.hpp"
#include "adjective_word.hpp"
#include "sustantive_word.hpp"
#include "verb_word.hpp"
#include "dictionary_term.hpp"
#include "dictionary_prefix.hpp"
#include "dictionary_suffix.hpp"
#include "dictionary_abbreviation.hpp"

#include <fstream>
#include <sstream>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"

using namespace rapidxml;
using namespace std;

namespace smtext
{
	vector<shared_ptr<dictionary_entry>> create_words_from_dictionary_file(const string& filename)
	{
		file<> file(filename.c_str());
		xml_document<> xml_file;
		xml_file.parse<0>(file.data());
		rapidxml::xml_node<> * root_node;
		root_node = xml_file.first_node("dictionary");
		vector<shared_ptr<dictionary_entry>> words = vector<shared_ptr<dictionary_entry>>();
		for (rapidxml::xml_node<>* word_node = root_node->first_node(); word_node; word_node = word_node->next_sibling())
		{
			if (string(word_node->name()) == "word")
			{
				string type = word_node->first_attribute("type") ? word_node->first_attribute("type")->value() : "";
				rapidxml::xml_node<>* es_node = word_node->first_node("es");
				string word_name = es_node->first_attribute("name") ? es_node->first_attribute("name")->value() : "";
				string word_description = es_node->value() ? es_node->value() : "";
				if (type =="adjective")
				{
					string plural_name = es_node->first_attribute("plural") ? es_node->first_attribute("plural")->value() : "";
					shared_ptr<dictionary_entry> new_adjective(new adjective_word(word_name,plural_name,word_description,language::spanish,word_type::adjective));
					words.push_back(new_adjective);
				}
				else if (type == "sustantive")
				{
					string plural_name = es_node->first_attribute("plural") ? es_node->first_attribute("plural")->value() : "";
					shared_ptr<dictionary_entry> new_sustantive(new sustantive_word(word_name,plural_name,word_description,language::spanish,word_type::sustantive));
					words.push_back(new_sustantive);
				}
				else if (type == "verb")
				{
					shared_ptr<dictionary_entry> new_verb(new verb_word(word_name,word_description,language::spanish,word_type::verb));
					words.push_back(new_verb);
				}
			}
			else if (string(word_node->name()) == "term")
			{
				rapidxml::xml_node<>* es_node = word_node->first_node("es");
				string term_name = es_node->first_attribute("name") ? es_node->first_attribute("name")->value() : "";
				string term_description = es_node->value() ? es_node->value() : "";
				string term_plural = es_node->first_attribute("plural") ? es_node->first_attribute("plural")->value() : "";
				shared_ptr<dictionary_entry> new_term (new dictionary_term(term_name,term_plural,term_description,language::spanish));
				words.push_back(new_term);
			}
			else if (string(word_node->name()) == "prefix")
			{
				rapidxml::xml_node<>* es_node = word_node->first_node("es");
				string prefix_name = es_node->first_attribute("name") ? es_node->first_attribute("name")->value() : "";
				string prefix_description = es_node->value() ? es_node->value() : "";
				shared_ptr<dictionary_entry> new_prefix (new dictionary_prefix(prefix_name,prefix_description,language::spanish));
				words.push_back(new_prefix);
			}
			else if (string(word_node->name()) == "suffix")
			{
				rapidxml::xml_node<>* es_node = word_node->first_node("es");
				string suffix_name = es_node->first_attribute("name") ? es_node->first_attribute("name")->value() : "";
				string suffix_description = es_node->value() ? es_node->value() : "";
				shared_ptr<dictionary_entry> new_suffix (new dictionary_suffix(suffix_name,suffix_description,language::spanish));
				words.push_back(new_suffix);
			}
			else if (string(word_node->name()) == "abbreviation")
			{
				rapidxml::xml_node<>* es_node = word_node->first_node("es");
				string abbreviation_name = es_node->first_attribute("name") ? es_node->first_attribute("name")->value() : "";
				string abbreviation_description = es_node->value() ? es_node->value() : "";
				shared_ptr<dictionary_entry> new_abbreviation (new dictionary_abbreviation(abbreviation_name,abbreviation_description,language::spanish));
				words.push_back(new_abbreviation);
			}
		}
		return words;
	}

	string validate_dictionary_file(const string& filename)
	{
		file<> file(filename.c_str());
		xml_document<> xml_file;
		xml_file.parse<0>(file.data());
		rapidxml::xml_node<> * root_node;
		root_node = xml_file.first_node("dictionary");
		ostringstream out;
		for (rapidxml::xml_node<>* word_node = root_node->first_node(); word_node; word_node = word_node->next_sibling())
		{
			string node_name = string(word_node->name());
			if (node_name != "prefix" and node_name != "term" and node_name != "word")
			{
				out << "The following node doesn't exist: " << node_name << endl;
				continue;
			}
			if (node_name == "prefix")
			{
				bool has_name = false;
				bool repeated_name = false;
				for (rapidxml::xml_attribute<>* node_attribute = word_node->first_attribute(); node_attribute; node_attribute = node_attribute->next_attribute())
				{
					string attribute_name = string(node_attribute->name());
					if (attribute_name != "name")
					{
						out << "The following attribute doesn't exist: '" << attribute_name << "'" << endl;
					}
					if (attribute_name == "name")
					{
						if (has_name)
						{
							repeated_name = true;
						}
						else
						{
							has_name = true;
						}
					}
				}
				if (!has_name)
				{
					out << "A term doesn't has name" << endl;
				}
				if (repeated_name)
				{
					out << "The term '" << string(word_node->first_attribute("name")->value()) << "' has a name repeated" << endl;
				}
			}
			if (node_name == "term")
			{
				bool has_name = false;
				bool repeated_name = false;
				for (rapidxml::xml_attribute<>* node_attribute = word_node->first_attribute(); node_attribute; node_attribute = node_attribute->next_attribute())
				{
					string attribute_name = string(node_attribute->name());
					if (attribute_name != "name")
					{
						out << "The following attribute doesn't exist: '" << attribute_name << "'" << endl;
					}
					if (attribute_name == "name")
					{
						if (has_name)
						{
							repeated_name = true;
						}
						else
						{
							has_name = true;
						}
					}
				}
				if (!has_name)
				{
					out << "A term doesn't has name" << endl;
				}
				if (repeated_name)
				{
					out << "The term '" << string(word_node->first_attribute("name")->value()) << "' has a name repeated" << endl;
				}
			}
			if (node_name == "word")
			{
				bool has_name = false;
				bool has_type = false;
				bool repeated_name = false;
				bool repeated_type = false;
				for (rapidxml::xml_attribute<>* node_attribute = word_node->first_attribute(); node_attribute; node_attribute = node_attribute->next_attribute())
				{
					string attribute_name = string(node_attribute->name());
					if (attribute_name != "name" and attribute_name != "type")
					{
						out << "The following attribute doesn't exist: '" << attribute_name << "'" << endl;
					}
					if (attribute_name == "name")
					{
						if (has_name)
						{
							repeated_name = true;
						}
						else
						{
							has_name = true;
						}
					}
					if (attribute_name == "type")
					{
						if (has_type)
						{
							repeated_type = true;
						}
						else
						{
							has_type = true;
						}
					}
				}
				if (!has_name)
				{
					if (has_type)
					{
						out << "A word doesn't has name" << endl;
					}
				}
				if (!has_type)
				{
					if (has_name)
					{
						out << "The word '" << string(word_node->first_attribute("name")->value()) << "' doesn't has type" << endl;
					}
					else
					{
						out << "A word doesn't has name and doesn't has type" << endl;
					}
				}
				if (repeated_name)
				{
					out << "The word '" << string(word_node->first_attribute("name")->value()) << "' has a name repeated" << endl;
				}
				if (repeated_type)
				{
					if (!has_name)
					{
						out << "A word has two types" << endl;
					}
					else
					{
						out << "The word '" << string(word_node->first_attribute("name")->value()) << "' has two types" << endl;
					}
				}
			}
		}
		return out.str();
	}
}

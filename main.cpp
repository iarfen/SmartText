#include "smarttext.hpp"
#include "smarttext_dictionary.hpp"

#include <iostream>
#include <memory>

using namespace std;

int main()
{
	vector<shared_ptr<smtext::dictionary_entry>> words = smtext::create_words_from_dictionary_file("dictionary_example.xml");
	for (const shared_ptr<smtext::dictionary_entry>& word : words)
	{
		cout << word << endl;
	}
	/*smtext::text new_text("Hello here! This is the new text. Helloooo",smtext::language::english);
	cout << new_text << endl;

	for (const smtext::line& line : new_text.get_lines())
	{
		cout << "New line: " << line << endl;
	}
	for (const smtext::word& word : new_text.get_words())
	{
		cout << "New word: " << word << endl;
	}*/
}

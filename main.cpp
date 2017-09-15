#include "smarttext.hpp"

using namespace std;

int main()
{
	smarttext::word new_word("a");
	wcout << new_word << endl;
	smarttext::line new_line("Hello here!",smarttext::language::spanish);
	wcout << new_line.get_start_punctuation() << endl;
	for (const smarttext::word& word : new_line.get_words())
	{
		wcout << word << endl;
	}
	wcout << new_line.get_final_punctuation() << endl;
}

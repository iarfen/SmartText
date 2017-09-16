#include "punctuation.hpp"

using namespace std;

namespace smarttext
{
	punctuation::punctuation(string new_chars) : chars(new_chars)
	{
	}

	wstring punctuation::display() const
	{
		wstring chars2 (chars.length(),L' ');
		copy(chars.begin(),chars.end(),chars2.begin());
		return chars2;
	}
}

wostream& operator <<(wostream& os, const smarttext::punctuation& x)
{
	return os << x.display();
}

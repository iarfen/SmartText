#include "punctuation.hpp"

using namespace std;

namespace smtext
{
	punctuation::punctuation() : chars()
	{
	}

	punctuation::punctuation(const string& new_chars) : chars(new_chars)
	{
	}

	string punctuation::display() const
	{
		string chars2 (chars.length(),L' ');
		copy(chars.begin(),chars.end(),chars2.begin());
		return chars2;
	}
}

bool operator ==(const smtext::punctuation& x,const smtext::punctuation& y)
{
	return (x.display() == y.display());
}

ostream& operator <<(ostream& os, const smtext::punctuation& x)
{
	return os << x.display();
}

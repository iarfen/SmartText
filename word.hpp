#ifndef WORD_HPP_INCLUDED
#define WORD_HPP_INCLUDED

#include <string>

using namespace std;

namespace smarttext
{
	class word
	{
		public:
			word(string);

		private:
			string chars;
	};
}

#endif // WORD_HPP_INCLUDED

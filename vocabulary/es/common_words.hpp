#ifndef SMARTTEXT_VOCABULARY_COMMON_WORDS_HPP_INCLUDED
#define SMARTTEXT_VOCABULARY_COMMON_WORDS_HPP_INCLUDED

#include "language.hpp"
#include "vocabulary/common_words.hpp"

#include <string>
#include <vector>

using namespace std;

namespace smtext
{
	template<>
	class common_words<language::spanish>
	{
		public:
			common_words()
			{
			}

			static const vector<string> name_of_days = {"lunes","martes","miércoles","jueves","viernes","sábado","domingo"};
			static const vector<string> name_of_months = {"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};
	};
}

#endif // SMARTTEXT_VOCABULARY_COMMON_WORDS_HPP_INCLUDED

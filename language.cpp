#include "language.hpp"

using namespace std;

namespace smarttext
{
	language get_language_from_iso(string iso)
	{
		if (iso == "EN")
		{
			return language::english;
		}
		else if (iso == "ES")
		{
			return language::spanish;
		}
	}
}

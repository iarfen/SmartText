#include "language.hpp"

using namespace std;

namespace smtext
{
	language get_language_from_iso(const string& iso)
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

	bool is_iso(const string& iso)
	{
		if (iso == "EN")
		{
			return true;
		}
		else if (iso == "ES")
		{
			return true;
		}
		return false;
	}
}

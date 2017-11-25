#ifndef SMARTTEXT_UTILITIES_PCRE_HPP_INCLUDED
#define SMARTTEXT_UTILITIES_PCRE_HPP_INCLUDED

#include <string>

#include "pcre.h"

using namespace std;

namespace smtext
{
	class sm_pcre
	{
		public:
			sm_pcre();
			explicit sm_pcre(const string&);
			~sm_pcre();

			inline string& get_regular_expression()
			{
				return regular_expression;
			}

			inline const string& get_regular_expression() const
			{
				return regular_expression;
			}

			bool match(const string&,int = 1) const;
			string replace(const string&,const string&) const;

		private:
			string regular_expression;
			pcre* compiled_regexp;
			const char* error;
			int error_offset;
	};

	class pcre_exception
	{
		public:
			pcre_exception();
			explicit pcre_exception(const string&,int);

			inline string& get_message()
			{
				return message;
			}

			inline const string& get_message() const
			{
				return message;
			}

			inline int& get_error_offset()
			{
				return error_offset;
			}

			inline const int& get_error_offset() const
			{
				return error_offset;
			}

		private:
			string message;
			int error_offset;
	};
}

#endif // SMARTTEXT_UTILITIES_PCRE_HPP_INCLUDED

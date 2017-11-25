#include "sm_pcre.hpp"

using namespace std;

namespace smtext
{
	sm_pcre::sm_pcre() : regular_expression(),compiled_regexp(),error(),error_offset()
	{
	}

	sm_pcre::sm_pcre(const string& new_regular_expression) : regular_expression(new_regular_expression),error(),error_offset()
	{
		compiled_regexp = pcre_compile(regular_expression.c_str(),0,&error,&error_offset,0);
		if (!compiled_regexp)
		{
			throw pcre_exception(error,error_offset);
		}
	}

	sm_pcre::~sm_pcre()
	{
		free(compiled_regexp);
	}

	bool sm_pcre::match(const string& scanned_text,int offset_max) const
	{
		int offsets[offset_max];
		int rc = pcre_exec(compiled_regexp,0,scanned_text.c_str(),scanned_text.size(),0,0,offsets,offset_max);
		if (rc < 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	string sm_pcre::replace(const string& scanned_text,const string& replace_pattern) const
	{
		return "";
	}

	pcre_exception::pcre_exception() : message(),error_offset()
	{
	}

	pcre_exception::pcre_exception(const string& new_message,int new_error_offset) : message(new_message),error_offset(new_error_offset)
	{
	}
}

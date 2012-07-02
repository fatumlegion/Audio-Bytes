#include "helper.h"
#include <algorithm>
#include <stdio.h>

bool StrToBool(std::string str)
{
	if (str == "true")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

std::vector<std::string> split( const std::string& s, const std::string& f )
{
    std::vector<std::string> temp;
    if ( f.empty() )
	{
        temp.push_back( s );
        return temp;
    }
    typedef std::string::const_iterator iter;
    const iter::difference_type f_size( distance( f.begin(), f.end() ) );
    iter i( s.begin() );
    for ( iter pos; ( pos = search( i , s.end(), f.begin(), f.end() ) ) != s.end(); )
	{
        temp.push_back( std::string( i, pos ) );
        advance( pos, f_size );
        i = pos;
    }
    temp.push_back( std::string( i, s.end() ) );
    return temp;
}

std::string trim_spaces(const std::string &str)
{
	const std::string pWhitespace = " \t";
	
	const size_t beginStr = str.find_first_not_of(pWhitespace);
	if (beginStr == std::string::npos)
	{
		return "";
	}

	const size_t endStr = str.find_last_not_of(pWhitespace);
	const size_t range = endStr - beginStr + 1;

	return str.substr(beginStr, range);
}


std::string trim(std::string str)
{
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	str = trim_spaces(str);
	return str;
}

std::string getAbsoluteFileName(std::string file)
{
	std::vector<std::string> bit = split(file, "/");
	
	return bit[bit.size() - 1];
}

bool fModError(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        return true;
    }
    else
    {
	    return false;
    }
}
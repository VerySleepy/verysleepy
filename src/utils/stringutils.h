/*=====================================================================
stringutils.cpp
---------------

Copyright (C) Nicholas Chapman

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

http://www.gnu.org/copyleft/gpl.html.
=====================================================================*/
#ifndef __STRINGUTILS_H__
#define __STRINGUTILS_H__


//NOTE: not all of this code has been used/tested for ages.
//Your mileage may vary; test the code before you use it!!!!

#include <string>
#include <assert.h>
#include <vector>
#include <sstream>


inline float stringToFloat(const std::wstring& s)
{
	return (float)_wtof(s.c_str());
}

inline int stringToInt(const std::wstring& s)
{
	return _wtoi(s.c_str());
}

inline double stringToDouble(const std::wstring& s)
{
	return _wtof(s.c_str());
}


unsigned int hexStringToUInt(const std::wstring& s);
unsigned long long hexStringTo64UInt(const std::wstring& s);

//const std::wstring toHexString(unsigned int i);//32 bit integers
const std::wstring toHexString(unsigned long long i);//for 64 bit integers
const std::wstring intToString(int i);
const std::wstring floatToString(float f);
const std::wstring doubleToString(double d);
const std::wstring floatToString(float f, int num_decimal_places);



//argument overloaded toString functions:
inline const std::wstring toString(double f)
{
	return doubleToString(f);
}

inline const std::wstring toString(float f)
{
	return floatToString(f);
}

inline const std::wstring toString(int i)
{
	return intToString(i);
}

inline const std::wstring toString(char c)
{
	return std::wstring(1, c);
}





__forceinline bool isWhitespace(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

__forceinline bool isAlpha(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

__forceinline bool isCToken(char c)
{
	return isAlpha(c) || c == '_' || c == '#';
}

void readQuote(std::wistream& stream, std::wstring& str_out);//reads string from between double quotes.

template<typename T>
void writeQuote(T& stream, const std::wstring& s, wchar_t escape = '\\')
{
	stream << '"';
	for (size_t i = 0; i < s.length(); i++)
	{
		wchar_t c = s[i];
		if (c == escape || c == '"')
			stream << escape;
		stream << c;
	}
	stream << '"';
}

struct StringSet
{
	std::vector<std::wstring>	strings;
	bool caseCheck;
public:
	StringSet(const wchar_t *file, bool caseCheck);
	void Add(const wchar_t *string);
	void Remove(const wchar_t *string);
	bool Contains(const wchar_t *string) const;
};


struct StringList
{
	std::wstring string;
public:
	StringList(const wchar_t *file);
	void Add(const wchar_t *str);
	const std::wstring& Get() const { return string; }
};

#endif //__STRINGUTILS_H__

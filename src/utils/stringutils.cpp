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
#include "stringutils.h"
#include <algorithm>
#include <shlwapi.h>


unsigned int hexStringToUInt(const std::wstring& s)
{
	if(s.size() < 3)
		return 0;//too short, parse error
	else if(s.size() > 10)
		return 0;//too long, parse error

	unsigned int i = 0;
	unsigned int x = 0;
	unsigned int nibble;

	//eat '0'
	if(s[i++] != '0')
		return 0;//parse error

	//eat 'x'
	if(s[i++] != 'x')
		return 0;//parse error

	while(i < s.size())
	{
		if(s[i] >= '0' && s[i] <= '9')
			nibble = s[i] - '0';
		else if(s[i] >= 'a' && s[i] <= 'f')
			nibble = s[i] - 'a' + 10;
		else if(s[i] >= 'A' && s[i] <= 'F')
			nibble = s[i] - 'A' + 10;
		else
			return 0;//parse error

		x <<= 4;
		x |= nibble;//set lower 4 bits to nibble

		i++;
	}

	return x;
}

unsigned long long hexStringTo64UInt(const std::wstring& s)
{
	assert(sizeof(unsigned long long) == 8);

	if(s.size() < 3)
		return 0;//too short, parse error
	else if(s.size() > 18)
		return 0;//too long, parse error

	unsigned int i = 0;
	unsigned long long x = 0;
	unsigned int nibble;

	//eat '0'
	if(s[i++] != '0')
		return 0;//parse error

	//eat 'x'
	if(s[i++] != 'x')
		return 0;//parse error

	while(i < s.size())
	{
		if(s[i] >= '0' && s[i] <= '9')
			nibble = s[i] - '0';
		else if(s[i] >= 'a' && s[i] <= 'f')
			nibble = s[i] - 'a' + 10;
		else if(s[i] >= 'A' && s[i] <= 'F')
			nibble = s[i] - 'A' + 10;
		else
			return 0;//parse error

		x <<= 4;
		x |= nibble;//set lower 4 bits to nibble

		i++;
	}

	return x;
}


/*const std::wstring toHexString(unsigned int i)
{

	//------------------------------------------------------------------------
	//build the hex string in reverse order
	//------------------------------------------------------------------------
	std::wstring reverse_s;
	unsigned int nibble;

	while(i != 0)
	{
		nibble = i & 0x0000000F;//get last 4 bits
		if(nibble <= 9)
			concatWithChar(reverse_s, '0' + nibble - 0);
		else
			concatWithChar(reverse_s, 'a' + nibble - 10);
	
		i >>= 4;//shift right 4 bits
	}

	if(reverse_s.empty())
	{
		//hex constants must have at least one digit :)
		return "0x0";
	}
	else
	{
		std::wstring s;
		s.resize(reverse_s.size());
		for(unsigned int z=0; z<s.size(); ++z)
			s[z] = reverse_s[reverse_s.size() - z - 1];

		return "0x" + s;
	}
}*/

//for 64 bit integers
//NOTE: this function is unchanged from the 32 bit version... so turn into template?
//or could cast 32 bit ints into 64 bit ints and always use this version.
const std::wstring toHexString(unsigned long long i)
{
	assert(sizeof(unsigned long long) == 8);

	//------------------------------------------------------------------------
	//build the hex string in reverse order
	//------------------------------------------------------------------------
	std::wstring reverse_s;
	unsigned long long nibble;

	while(i != 0)
	{
		nibble = i & 0x000000000000000F;//get last 4 bits
		if(nibble <= 9)
			concatWithChar(reverse_s, '0' + (char)nibble - 0);
		else
			concatWithChar(reverse_s, 'a' + (char)nibble - 10);
	
		i >>= 4;//shift right 4 bits
	}

	if(reverse_s.empty())
	{
		//hex constants must have at least one digit :)
		return L"0x0";
	}
	else
	{
		std::wstring s;
		s.resize(reverse_s.size());
		for(unsigned int z=0; z<s.size(); ++z)
			s[z] = reverse_s[reverse_s.size() - z - 1];

		return L"0x" + s;
	}
}

const std::wstring intToString(int i)
{
	//not static for thread-safety.
	wchar_t buffer[100];

	swprintf(buffer, 100, L"%i", i);

	return std::wstring(buffer);
}

const std::wstring floatToString(float f)
{
	//not static for thread-safety.
	wchar_t buffer[100];

	swprintf(buffer, 100, L"%.3f", (double)f);

	return std::wstring(buffer);
}

const std::wstring doubleToString(double d)
{
	//not static for thread-safety.
	wchar_t buffer[100];

	swprintf(buffer, 100, L"%f", d);

	return std::wstring(buffer);
}

const std::wstring floatToString(float f, int num_decimal_places)
{
	//not static for thread-safety.
	wchar_t buffer[100];


	assert(num_decimal_places >= 0);

	if(num_decimal_places >= 10)
		num_decimal_places = 9;

	const std::wstring format_string = L"%1." + ::toString(num_decimal_places) + L"f";

	swprintf(buffer, 100, format_string.c_str(), (double)f);

	return std::wstring(buffer);


	//not static for thread-safety.
	/*char buffer[100];

	const std::wstring format_string = "%1.xf";

	assert(num_decimal_places >= 0);

	if(num_decimal_places >= 10)
		num_decimal_places = 9;
	
	const std::wstring dec_string = intToString(num_decimal_places);
	assert(dec_string.size() == 1);

	format_string[3] = dec_string[0];
	//format[4] = 'f';
	//format[5] = 0;

	//"%1.2f"

	sprintf(buffer, format_string.c_str(), f);

	return std::wstring(buffer);*/
}


const std::wstring toString(unsigned int x)
{
	wchar_t buffer[100];

	swprintf(buffer, 100, L"%u", x);

	return std::wstring(buffer);
}




void readQuote(std::wistream& stream, std::wstring& str_out)//reads string from between double quotes.
{
	wchar_t c;
	str_out = L"";

	//------------------------------------------------------------------------
	//parse to first "
	//------------------------------------------------------------------------
	while(1)
	{
		stream.get(c);
		if(!stream.good() || c == '"')
			break;
	}

	//------------------------------------------------------------------------
	//parse quoted text, to next "
	//------------------------------------------------------------------------	
	while(1)
	{
		stream.get(c);
		if(!stream.good() || c == '"')
			break;
		else
			::concatWithChar(str_out, c);
	}
		




	/*stream >> str_out;
	if(str_out.empty() || str_out[0] != '\"')
		return;

	str_out = getTailSubString(str_out, 1);//lop off quote

	if(::hasSuffix(str_out, "\""))
	{
		str_out = str_out.substr(0, str_out.size() - 1);
		return;
	}

	//------------------------------------------------------------------------
	//read thru char by char until hit next quote
	//------------------------------------------------------------------------
	while(stream.good())
	{
		char c;
		stream.get(c);

		if(c == '\"')
			break;

		::concatWithChar(str_out, c);
	}*/
}


StringSet::StringSet(const wchar_t *file, bool caseCheck)
{
	FILE *fp;
	wchar_t path[MAX_PATH];
	wcscpy(path, file);

	this->caseCheck = caseCheck;
	fp = _wfopen(path, L"r");
	
	if (!fp) {
		GetModuleFileName(NULL, path, MAX_PATH);
		PathRemoveFileSpec(path);

		do
		{
			PathAppend(path, file);
			fp = _wfopen(path, L"r");
		}
		while (!fp && PathRemoveFileSpec(path) && PathRemoveFileSpec(path));
	}

	if (!fp)
		return;

	wchar_t line[4096];
	while(fgetws(line, 4096, fp))
	{
		wchar_t *start = line;
		while(*start && isspace(*start))
			start++;

		if (*start == 0)
			continue;

		wchar_t *end = line+wcslen(line)-1;
		while(end != start && isspace(*end))
			*end-- = 0;

		Add(start);
	}
	fclose(fp);
}

void StringSet::Add(const wchar_t *string)
{
	wchar_t *tmp = wcsdup(string);
	if (!caseCheck)
		wcslwr(tmp);
	strings.push_back(tmp);
	free(tmp);

	std::sort(strings.begin(), strings.end());
}

void StringSet::Remove(const wchar_t *string)
{
	wchar_t *tmp = wcsdup(string);
	if (!caseCheck)
		wcslwr(tmp);

	for (size_t n=0;n<strings.size();n++)
	{
		if (strings[n] == tmp)
		{
			strings.erase(strings.begin()+n);
			break;
		}
	}

	free(tmp);
	std::sort(strings.begin(), strings.end());
}

bool StringSet::Contains(const wchar_t *str) const
{
	size_t low = 0, high = strings.size();
	while(low < high)
	{
		size_t guess = (low + high) >> 1;
		const wchar_t *cmp = strings[guess].c_str();
		int match;

		if (caseCheck)
			match = wcscmp(str, cmp);
		else
			match = wcsicmp(str, cmp);

		if (match < 0)
			high = guess;
		else if (match > 0)
			low = guess+1;
		else
			return true;
	}

	return false;
}

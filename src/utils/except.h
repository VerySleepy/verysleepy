#pragma once

#include <stdexcept>
#include <string>

class SleepyException : public std::runtime_error
{
	std::wstring _what;

public:
	SleepyException(const std::string &what)
		: _what(std::wstring(what.begin(), what.end())), std::runtime_error(what) {}

	SleepyException(const std::wstring &what)
		: _what(what), std::runtime_error(std::string(what.begin(), what.end())) {}

	SleepyException(const wchar_t *what)
		: _what(std::wstring(what)), std::runtime_error(std::string(_what.begin(), _what.end())) {}

	const std::wstring &wwhat() { return _what; }
};

template<typename T, typename S>
static T enforce(T cond, const S &text)
{
	if (cond)
		return cond;
	throw SleepyException(text);
}

#include <windows.h>

template<class T, class S>
T wenforce(T cond, const S& where)
{
	if (cond)
		return cond;

	DWORD code = GetLastError();

	std::wostringstream message;
	if (where)
		message << where;

	if (code)
	{
		wchar_t *lpMsgBuf = NULL;
		FormatMessageW(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			code,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPWSTR)&lpMsgBuf,
			0,
			NULL);

		message << ": " << lpMsgBuf;
		if (lpMsgBuf)
			LocalFree(lpMsgBuf);
		message << " (error " << code << ")";
	}
	else
		message << " failed";

	throw SleepyException(message.str());
}

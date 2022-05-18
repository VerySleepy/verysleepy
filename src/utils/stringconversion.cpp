#include "stringconversion.h"
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#include <vector>

std::string toANSI(const wchar_t* what) {
	const int srcLength = (int)wcslen(what);
	const int destLength = ::WideCharToMultiByte(CP_ACP, 0, what, srcLength, nullptr, 0, nullptr, nullptr);
	std::vector<char> destBuffer;
	destBuffer.resize(destLength);
	::WideCharToMultiByte(CP_ACP, 0, what, srcLength, destBuffer.data(), destLength, nullptr, nullptr);
	return std::string(destBuffer.begin(), destBuffer.end());
}

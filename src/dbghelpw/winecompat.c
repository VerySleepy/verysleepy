// RJM- small compatibility library for Wine
#include "config.h"
#include "wine/port.h"
#include "windef.h"
#include "winbase.h"
#include "winternl.h"
#include "wine/debug.h"
#include <stdio.h>

void (*wineDbgPrint)(const char *str) = NULL;

// RJM- added a simple way to get debug info back out.
void WINAPI SymSetDbgPrint( void (*fn)(const char *str) )
{
	wineDbgPrint = fn;
}

int wine_dbg_printf( const char *format, ... ) __WINE_PRINTF_ATTR(1,2)
{
	char buffer[1024];
	va_list args;
	va_start(args, format);
	vsprintf(buffer,format, args);

	if (wineDbgPrint)
		wineDbgPrint(buffer);
	
	va_end(args);
	return 0;
}

const char *wine_dbg_sprintf( const char *format, ... ) __WINE_PRINTF_ATTR(1,2)
{
	static char buffer[2048];
	va_list args;
	va_start(args, format);
	vsprintf(buffer,format, args);
	va_end(args);
	return buffer;
}

const char *wine_dbgstr_an( const char * str, int n )
{
  	static char buffer[2048];
    static const char hex[16] = "0123456789abcdef";
    char *dst, *res;
    size_t size;

    if (!((ULONG_PTR)str >> 16))
    {
        if (!str) return "(null)";
        res = buffer;
        sprintf( res, "#%04x", LOWORD(str) );
        return res;
    }
    if (n == -1) n = strlen(str);
    if (n < 0) n = 0;
    size = 10 + min( 300, n * 4 );
    dst = res = buffer;
    *dst++ = '"';
    while (n-- > 0 && dst <= res + size - 9)
    {
        unsigned char c = *str++;
        switch (c)
        {
        case '\n': *dst++ = '\\'; *dst++ = 'n'; break;
        case '\r': *dst++ = '\\'; *dst++ = 'r'; break;
        case '\t': *dst++ = '\\'; *dst++ = 't'; break;
        case '"':  *dst++ = '\\'; *dst++ = '"'; break;
        case '\\': *dst++ = '\\'; *dst++ = '\\'; break;
        default:
            if (c >= ' ' && c <= 126)
                *dst++ = c;
            else
            {
                *dst++ = '\\';
                *dst++ = 'x';
                *dst++ = hex[(c >> 4) & 0x0f];
                *dst++ = hex[c & 0x0f];
            }
        }
    }
    *dst++ = '"';
    if (n > 0)
    {
        *dst++ = '.';
        *dst++ = '.';
        *dst++ = '.';
    }
    *dst++ = 0;
    return res;
}

const char *wine_dbgstr_wn( const WCHAR *str, int n )
{
 	static char buffer[2048];
    char *dst, *res;
    size_t size;

    if (!((ULONG_PTR)str >> 16))
    {
        if (!str) return "(null)";
        res = buffer;
        sprintf( res, "#%04x", LOWORD(str) );
        return res;
    }
    if (n == -1)
    {
        const WCHAR *end = str;
        while (*end) end++;
        n = end - str;
    }
    if (n < 0) n = 0;
    size = 12 + min( 300, n * 5 );
    dst = res = buffer;
    *dst++ = '"';
    while (n-- > 0 && dst <= res + size - 10)
    {
        WCHAR c = *str++;
        switch (c)
        {
        case '\n': *dst++ = '\\'; *dst++ = 'n'; break;
        case '\r': *dst++ = '\\'; *dst++ = 'r'; break;
        case '\t': *dst++ = '\\'; *dst++ = 't'; break;
        case '"':  *dst++ = '\\'; *dst++ = '"'; break;
        case '\\': *dst++ = '\\'; *dst++ = '\\'; break;
        default:
            if (c >= ' ' && c <= 126)
                *dst++ = c;
            else
            {
                *dst++ = '\\';
                sprintf(dst,"%04x",c);
                dst+=4;
            }
        }
    }
    *dst++ = '"';
    if (n > 0)
    {
        *dst++ = '.';
        *dst++ = '.';
        *dst++ = '.';
    }
    *dst++ = 0;
    return res;}

int wine_dbg_log( enum __wine_debug_class cls, struct __wine_debug_channel *ch, const char *func,
                         const char *format, ... ) __WINE_PRINTF_ATTR(4,5)
{
	if (cls == __WINE_DBCL_TRACE || cls == __WINE_DBCL_ERR)
		return 0;
	return -1;
}

unsigned char __wine_dbg_get_channel_flags( struct __wine_debug_channel *channel )
{
	return 0;
}

int strcmpiW( const WCHAR *str1, const WCHAR *str2 )
{
	return wcsicmp( str1, str2 );
}

int strncmpiW( const WCHAR *str1, const WCHAR *str2, int n )
{
	return wcsnicmp( str1, str2, n );
}

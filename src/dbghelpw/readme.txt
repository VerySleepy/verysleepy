This is the source to dbghelp.dll, taken from Wine version 1.3.32

This is licensed under the LGPL - see LICENSE

All changes to the source have been marked with RJM

I also commented out some TRACE calls that were cluttering the place up.
Added some NTDLL import libs, brought over casemap.c from wine, and
added some compatibility stubs.

Optimized the dwarf symbol lookup code.
Some changes to support compiling a Wow64 build (64-bit code, using
32-bit definitions), which includes a few changes in the wine winnt.h and friends.

A few other random fixes.

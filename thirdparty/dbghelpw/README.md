dbghelpw (Windows version of Wine's dbghelp) is now
being maintained in a fork of the Wine git repository:

https://github.com/VerySleepy/wine

You can find the respective files on the `sleepy` branch,
under `dlls/dbghelp`. The Visual Studio project and solution
is in the `vs` subdirectory.

It is also registered in this repository as a Git submodule.
You can get it by running:

    git submodule init
    git submodule update

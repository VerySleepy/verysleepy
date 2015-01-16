Very Sleepy
-----------

This is [Very Sleepy](http://www.codersnotes.com/sleepy), a polling Windows CPU profiler with a wxWidgets-based GUI.

### Download

You can download an installer on [the project's website](http://www.codersnotes.com/programs/sleepy), or from [the GitHub releases page](https://github.com/CyberShadow/verysleepy/releases).

### History

##### Version 0.91 (under development):

* Rename project back to Very Sleepy (this fork repository is now the official repository)

##### Version 0.90 (2014-12-23):

* Redesign parts of the file format and internal database representation, to allow more exact late symbol loading, as well as a disassembler view in the future
* Add an "Address" column to all function lists
  * For the call stack and callers view, the address specifies the address past the call instruction
* Several fixes to the crash reporter
* Use wxWidgets 2.9.5
* Fix problems caused by dbghelp.dll hijacking
* Fix handling of symbols containing whitespace characters
* More user interface improvements
* Contributed by Michael Vance:
    * Add CSV export for the callstack view
    * UI fixes and code cleanup

##### Version 0.83 (2013-08-22):

* Rename fork to "Very Sleepy CS"
* Numerous user interface performance, responsiveness and usability improvements
* Allow specifying additional symbol search paths
* Add Back and Forward menu items and hotkeys for function list navigation
* Improve overall performance
* Add late symbol loading by saving a minidump during profiling
* Install 32-bit version alongside 64-bit version
* Contributed by [Richard Munn](https://github.com/benjymous):
    * Added a time limit option to the interface
    * Added function highlighting and filtering

##### [First release](http://blog.thecybershadow.net/2013/01/11/very-sleepy-fork/) (2013-01-11):

* Fix several issues with the `/r` command-line option
* Various UI improvements
* Don't completely abort due to one failed `GetThreadContext` call (fixes "`Error: ProfilerExcep: GetThreadContext failed.`" errors by ignoring the occasional seemingly-harmless error condition)

### Motivation

This project exists because all of my recent attempts to contact Richard Mitton, Very Sleepy's maintainer, have failed.
The patches I have sent him in March 2012 have not been published,
and my requests to upload the project's source code on a source forge (e.g. GitHub) have similarly fallen on deaf ears.

Several others have started their own forks of the project as well.
Although I hope that I will be able to reach Richard eventually,
for now I'd like for there to be one place for further project development,
so that orphaned forks (which often remain unnoticed and succumb to bitrot) could be avoided.

### Building

Prerequisites:

* Visual C++ 2010 (or compatible, e.g. 2012)
* [wxWidgets 2.9.5](http://sourceforge.net/projects/wxwindows/files/2.9.5/)
  * Versions other than 2.9.5 might work, but may have compatibility issues.

After building wxWidgets (see below), you can build Sleepy using the project files (with the Visual Studio IDE or msbuild).

#### Building wxWidgets

Run one of the Microsoft batch files to set up the Visual Studio environment:

    cd "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\bin"
    vcvars32.bat           // for a regular 32-bit compile
    vcvars64.bat           // for a regular 64-bit build
    vcvarsx86_amd64.bat    // for a 64-bit cross-compile

Now, from the wxWidgets `build\msw` directory:

    nmake -f makefile.vc BUILD=debug SHARED=0 RUNTIME_LIBS=static

NMAKE is part of Visual Studio, so vcvars should have added it to your path.

Options:

* For a release build, use `BUILD=release` instead.
* For 64-bit, add `TARGET_CPU=AMD64`.
* You could also use the Visual Studio project/solution files to build wxWidgets, however (as of 2.9.5) these are Win32-only.

Finally, create an environment variable called `WXWIN`, and set it to the full path towards the wxWidgets directory (incl. trailing backslash).
This variable in referenced in Sleepy's project files - Visual Studio must have in in its environment to be able to find wxWidgets.

### Contributing

If you'd like to contribute a patch, please [open a pull request](https://github.com/CyberShadow/verysleepy/pulls). I'll try to review and merge it as soon as my time will allow.

Bug reports and feature requests are welcome as well - please file them as [GitHub issues](https://github.com/CyberShadow/verysleepy/issues).

Very Sleepy [![Build status](https://ci.appveyor.com/api/projects/status/5gf55tjd7mc80b05/branch/master?svg=true)](https://ci.appveyor.com/project/CyberShadow/verysleepy/branch/master)
-----------

This is [Very Sleepy](http://www.codersnotes.com/sleepy), a polling Windows CPU profiler with a wxWidgets-based GUI.

![Very Sleepy screenshot](https://dump.thecybershadow.net/12df19e403014f88f368da4c2d2482a2/1.png)

### Features

* Simple user interface
* Microsoft Symbol Server support
* [Command-line operation](https://github.com/VerySleepy/verysleepy/wiki/Command-Line-Usage)
* [MinGW support](https://github.com/VerySleepy/verysleepy/wiki/Profiling-MinGW-Programs)
* [Late symbol resolution](https://github.com/VerySleepy/verysleepy/wiki/Late-Symbol-Resolution)

### Documentation

Very Sleepy documentation is available on [the GitHub project wiki](https://github.com/VerySleepy/verysleepy/wiki).

### Download

Official releases can be downloaded from [the project's website](http://www.codersnotes.com/sleepy), or from [the GitHub releases page](https://github.com/VerySleepy/verysleepy/releases).

For the latest development version, you can download [the latest AppVeyor artifact](https://ci.appveyor.com/api/projects/CyberShadow/verysleepy/artifacts/setup.exe?branch=master).

### History

##### Version 0.91 (under development):

* Rename project back to Very Sleepy (this fork repository is now the official repository)
* Use [Dr. MinGW](https://github.com/jrfonseca/drmingw) to resolve MinGW symbols by default
* Update Wine DbgHelp for Windows
* Improve and greatly simplify build process ([#40](https://github.com/VerySleepy/verysleepy/pull/40))
* Add continuous integration via [AppVeyor](https://ci.appveyor.com/project/CyberShadow/verysleepy)
* Improve Visual Studio 2015 support ([#28](https://github.com/VerySleepy/verysleepy/issues/28))
* More user interface fixes and improvements
* Contributed by [Bernat Muñoz Garcia](https://github.com/shashClp):
    * Use Scintilla for syntax highlighting ([#16](https://github.com/VerySleepy/verysleepy/pull/16))
* Contributed by [Ashod](https://github.com/Ashod):
    * 64-bit fixes ([#21](https://github.com/VerySleepy/verysleepy/pull/21))
* Contributed by [k4hvd1](https://github.com/k4hvd1):
    * Added command-line option `/a` to profile an existing process by its process ID ([#30](https://github.com/VerySleepy/verysleepy/pull/30))
* Contributed by [Markus Gaisbauer](https://github.com/quijote):
    * Added "Total CPU time" column ([#37](https://github.com/VerySleepy/verysleepy/pull/37))
    * Improved handling of processes with many threads ([#38](https://github.com/VerySleepy/verysleepy/pull/38))
* Contributed by [Bernhard Schelling](https://github.com/schellingb):
    * Added Callgrind format file export feature ([#46](https://github.com/VerySleepy/verysleepy/pull/46))

##### Version 0.90 (2014-12-23):

* Redesign parts of the file format and internal database representation, to allow more exact late symbol loading, as well as a disassembler view in the future
* Add an "Address" column to all function lists
  * For the call stack and callers view, the address specifies the address past the call instruction
* Several fixes to the crash reporter
* Use wxWidgets 2.9.5
* Fix problems caused by dbghelp.dll hijacking
* Fix handling of symbols containing whitespace characters
* More user interface improvements
* Contributed by [Unknown W. Brackets](https://github.com/unknownbrackets):
    * 64-bit fixes ([#6](https://github.com/VerySleepy/verysleepy/pull/6))
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
    * Added a time limit option to the interface ([#1](https://github.com/VerySleepy/verysleepy/pull/1))
    * Added function highlighting and filtering ([#2](https://github.com/VerySleepy/verysleepy/pull/2))
    * Interface improvements ([#3](https://github.com/VerySleepy/verysleepy/pull/3))

##### [First fork release](http://blog.thecybershadow.net/2013/01/11/very-sleepy-fork/) (2013-01-11):

* GitHub repository created
* Fix several issues with the `/r` command-line option
* Various UI improvements
* Don't completely abort due to one failed `GetThreadContext` call (fixes "`Error: ProfilerExcep: GetThreadContext failed.`" errors by ignoring the occasional seemingly-harmless error condition)

##### Older changes

Changes before this repository's creation can be found on [the project's website](http://www.codersnotes.com/programs/sleepy).

### Building

#### Prerequisites

* Visual C++ 2010 or newer
* [CMake](https://cmake.org/) (for Dr. MinGW)
* [7-Zip](http://www.7-zip.org/) (for unpacking MinGW)
* [InnoSetup 5](http://www.jrsoftware.org/isinfo.php) (for building an installer)

#### Instructions

Third party dependencies are registered using git submodules, so you will need to either clone with the `--recursive` flag, or run `git submodule update --init` after cloning.

The `build.cmd` batch file will attempt to build Very Sleepy and its dependencies.

Alternatively, you can build Dr. MinGW using the `thirdparty/drmingw_build_mingw.cmd` batch file, then use the Visual Studio solution file (`sleepy.sln`) to build everything else.

### Contributing

If you'd like to contribute a patch, please [open a pull request](https://github.com/VerySleepy/verysleepy/pulls). I'll try to review and merge it as soon as my time will allow.

Bug reports and feature requests are welcome as well - please file them as [GitHub issues](https://github.com/VerySleepy/verysleepy/issues).

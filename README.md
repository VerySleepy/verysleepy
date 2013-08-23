Very Sleepy CS
--------------

This project is a fork of [Very Sleepy](http://www.codersnotes.com/sleepy), a polling Windows CPU profiler with a wxWidgets-based GUI. It is based on Very Sleepy version 0.82, and adds several improvements.

### Download

You can download an installer on [files.thecybershadow.net](http://files.thecybershadow.net/verysleepy).

### History

##### Version 0.83 (2013-08-22):

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

### Contributing

If you'd like to contribute a patch, please [open a pull request](https://github.com/CyberShadow/verysleepy/pulls). I'll try to review and merge it as soon as my time will allow.

Bug reports and feature requests are welcome as well - please file them as [GitHub issues](https://github.com/CyberShadow/verysleepy/issues).

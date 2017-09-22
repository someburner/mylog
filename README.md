# mylog

Simple cpp logger- mostly stolen from [tacopie](https://github.com/Cylix/tacopie), which worked well (thx dude), but
I found the formatting to be far too verbose, and obviously not trying to link against tacopie for all my projects.. or use
cmake..

<br>

## Install

**Before installing:** glance at the top of the Makefile and make sure the install location is kosher. Written by an Ubuntu user so directories are:

* `/usr/local/include/mylog`: aka creates `mylog` folder and copies **mylog.hpp** there.
* `/usr/local/lib`: **mylog.a** will be copied here.

*Then..*

```sh
git clone https://github.com/someburner/mylog.git
cd mylog
make
sudo make install
```

<br>

## Usage

Copy the `example_debug.h` into your project (can be named whatever), and `#include "whatever_you_named_it.h"` into your `main.cpp`. 

Then in your `main()` (or wherever you want to enable the lib), add something like:

```cpp
   try {
      MYLOG::active_logger = std::unique_ptr<MYLOG::logger>(new MYLOG::logger(MYLOG::logger::log_level::okay));
   } catch (std::exception& e) {
      std::cout << "Oh dear :( [" << e.what() << "]" << std::endl;
      exit(1);
   }
```

Once the above is executed, you can call the methods like so:

```cpp
...

   std::cout << "Im normal" << std::endl;
   log("Im debug");
   logokay("Im okay");
   loginfo("Im info");
   logwarn("Im warn");
   logerror("Im error");

...
```

### "reserved" defines

In the sample include you might notice the *reserved* thing saying to look at the readme. The purpose behind that is to allow more flexibility in the case that you want to use the logger in your own libraries (in addition to your main application). A simple example to explain how this might look:

Let's say you have a library you're linking against. or maybe even just a less-used service in your main application. And say your library/service is not perfect and you want to debug it, but you don't want to recompile the whole thing and reinstall it every time. In that case, you would:

* First use the "verbose" logs (`vinfo()`, `vdebug`, `vall()`) in your library/service code (you can add others).
* Then recompile, reinstall that library. Now you can enable those at compile time in your main app code.
* Now in your app code:

**1**: Switch the `#define`s for those from `0` to `1` in your debug.h

**2**: Recompile and run.

<br>

### About

More-or-less everything the original tacopie logger had, but these edits:

* add more log-levels- `okay`, `info`, `vinfo`, `vdebug`, and `vall`.
* added colors for those
* `LL_DEBUG` is invoked with just `log("sup");`
* added lots of ifdefs so that, by default, nothing is enabled, and they can be switched on/off selectively.

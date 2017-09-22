# mylog

Simple cpp logger- mostly stolen from [tacopie](https://github.com/Cylix/tacopie), which worked well (thx dude), but
I found the formatting to be far too verbose, and obviously not trying to link against tacopie for all my projects.. or use
cmake..

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


### About

More-or-less everything the original tacopie logger had, but these edits:

* add more log-levels- `okay`, `info`, `vinfo`, `vdebug`, and `vall`.
* added colors for those
* `LL_DEBUG` is invoked with just `log("sup");`
* ^ speaking of, added lots of ifdefs so that, by default, nothing is enabled, and they can be switched on/off selectively.

############################
##
#### MyLog Makefile
##
############################

TARGET  := libmylog.a

############################
# Directories
############################
CPP_SRC_DIR = $(PWD)

BUILD_DIR =.

INSTALL_INC_DIR  = /usr/local/include/mylog
INSTALL_LIB_PATH = /usr/local/lib/$(TARGET)
############################

############################
# Flags
############################
## Linker
CPPLIBS =
# CPPLIBS = -luWS -lcpp_redis -ltacopie -lssl -lcrypto -lz -lfmt
# CPPLIBS += -lpthread -lboost_thread -lboost_system
## C flags
DEFINES  = -std=c++17 -DMYLOG_ENABLED
#-DUSE_ASIO

DEBUG_FLAGS = -Wall -Wextra -pedantic -O3 -D_REETRANT

## Collections - main
CPPFLAGS    := $(DEBUG_FLAGS) $(DEFINES)

############################
# Rules
############################
## Client
CPP_SOURCES = $(wildcard $(CPP_SRC_DIR)/*.cpp) $(wildcard $(CPP_SRC_DIR)/dep/*.cpp)
CPP_OBJECTS = $(patsubst $(CPP_SRC_DIR)/%.cpp, %.o, $(CPP_SOURCES))


############################
# Directives
############################

.PHONY: prebuild install postbuild clean

################################ Logger library ################################
all: prebuild libmylog.a postbuild
	@echo "done"

$(CPP_OBJECTS): %.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

libmylog.a: mylog.o
	ar rcs $@ $(LIBS) mylog.o

prebuild:
	@echo "pre-build"

clean:
	rm -f mylog.o libmylog.a

install:
	mkdir -p $(INSTALL_INC_DIR)
	cp -f mylog.h $(INSTALL_INC_DIR)/mylog.h
	cp -f mylog.hpp $(INSTALL_INC_DIR)/mylog.hpp
	cp -f $(TARGET) $(INSTALL_LIB_PATH)

####################################################################################




#### EOF

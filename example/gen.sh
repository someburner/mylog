#!/bin/bash


compile() {
DBGFLAGS="-ggdb -fPIC -pedantic -O0 -D_REETRANT -std=c++17 -DMYLOG_ENABLED"
USR_INC=/usr/local/include
g++ -I$USR_INC/ $DBGFLAGS main.cpp -o log -lmylog -lpthread
}

teelog() {
./log | tee -a > /opt/var/log/test.log
}


compile;

#teelog;

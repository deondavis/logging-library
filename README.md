# logging-library
thread safe logging library in c++

code reworked from https://gist.github.com/kevinkreiser/39f2e39273c625d96790

to use
```
cd loggerLib
mkdir build
cd build
cmake ..
make
make install
```
to test
```
cd logger_app
mkdir build
cd build
cmake ..
make
./logger_app
```
this creates a log file as configured in the Cfg json.

Note: please install jsoncpp as this uses this library for runtime configuration, the dependent codes can be commented
      if u need a stand alone system.

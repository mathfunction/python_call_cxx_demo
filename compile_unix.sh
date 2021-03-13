g++ --version
g++ -std=c++11 -fPIC -shared -O3 -o "build/cxxDevice.so" "src/cxxDevice.cpp" -I"./src" -I"./src/thirdparty"
g++ --version
g++ -fPIC -shared -O3 -o "build/cxxDevice.so" "src/cxxDevice.cpp" -I"./src" -I"./src/thirdparty"
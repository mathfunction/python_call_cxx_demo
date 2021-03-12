g++ --version
g++ -fPIC -shared -O3 -o "lib/cxxDevice.so" "src/cxxDevice.cpp" -I"./src" -I"./thirdparty"
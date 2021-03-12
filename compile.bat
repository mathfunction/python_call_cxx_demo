g++ --version
g++ -fPIC -shared -O3 -o "lib/cxxDevice.dll" "src/cxxDevice.cpp" -I"./src" -I"./thirdparty"
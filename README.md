# Python call C++ 

### Dependency:

| cxxDeviceModule.py      | cxxDevice.cpp    | 備註說明                  |
| ----------------------- | ---------------- | ------------------------- |
| passIntNumpySameShape   | passIntPointer   | 需額外寫定 input shape    |
| passFloatNumpySameShape | passFloatPointer | 需額外寫定 input shape    |
| passJson                | passJson         | 使用第三方 nlohmann::json |
| passStr                 | passString       |                           |
|                         |                  |                           |

### support c++ compiler:

- msys2-g++  for win
- gnu-g++ for linux
- clang++ for mac 

### where to implment C++ Project:

- check "cxxDevice_impl.hpp"!!

### how to compile:

In Terminal:  

```shell
g++ -std=c++11 -fPIC -shared -O3 -o "build/cxxDevice.so" "src/cxxDevice.cpp" -I"./src" -I"./src/thirdparty"
```

[PS] msys2 (.so) can work , without msvc (.dll) framework

### run hello world:

```
cd examples
python hello.py
```



### how to import:

```python
import sys
sys.path.append("[Dir]/build")
import cxxDeviceModule as cxx
# cxx.passXXXX(funcname,d)
```






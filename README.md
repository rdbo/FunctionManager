# FunctionManager
# Usage
Usage for fman.h + fman.cpp
The functions only have one type, which is <i>functype</i>, defined in fman.h
```C++
FunctionManager::Register("FunctionName", []() -> functype { /*function code*/ }, bOverwrite /*overwrite function with same name*/)
```
OBS: bOverwrite is defined as true by default in both cases
Example:
```C++
FunctionManager::Register("ExampleFunc", []() -> functype { return 1337; }, false);
FunctionManager::Call("ExampleFunc");
```
2. Usage for fman.hpp
The functions can have any type, everything is defined on this single file (no need of fman.cpp)
OBS: bOverwrite is defined as true by default in both cases
```C++
FunctionManager::Register<type_here>("FunctionName", []() -> type_here { /*function code*/ }, bOverwrite /*overwrite function with same name*/)
```
Example:
```C++
FunctionManager::Register<std::string>("ExampleFunc", []() -> std::string { return "hello"; }, false);
FunctionManager::Call<std::string>("ExampleFunc");
```
3. Additional notes
.To add variables into the scope of the function, put them between \[ and ] on the lambda function. Example: 
```C++
int a = 10;
FunctionManager::Register<void>("Example", [&a]() -> void { std::cout << a << std::endl });
```

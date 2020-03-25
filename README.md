# FunctionManager
<h1>Usage</h1>
<p><b>1. Usage for fman.h + fman.cpp</p></b>
<p><b>The functions only have one type, which is <i>functype</i>, defined in fman.h</p></b>
```C++
FunctionManager::Register("FunctionName", []() -> functype { /*function code*/ }, bOverwrite /*overwrite function with same name*/)
```
<p>OBS: bOverwrite is defined as true by default in both cases</p>
<p>Example:</p></br>
```C++
FunctionManager::Register("ExampleFunc", []() -> functype { return 1337; }, false);</p></i>
FunctionManager::Call("ExampleFunc");</p></i>
```
</br>
</br>
<p><b>2. Usage for fman.hpp</p></b>
<p><b>The functions can have any type, everything is defined on this single file (no need of fman.cpp)</p></b>
<p>OBS: bOverwrite is defined as true by default in both cases</p>
<p><i>FunctionManager::Register&lt;type_here>("FunctionName", []() -> type_here { /*function code*/ }, bOverwrite /*overwrite function with same name*/)</p></i>
<p>Example:</p></br>
```C++
FunctionManager::Register&lt;std::string>("ExampleFunc", []() -> std::string { return "hello"; }, false);</p></i>
FunctionManager::Call&lt;std::string>("ExampleFunc");</p></i>
```
</br>
</br>
<p><b>3. Additional notes </p></b>
<ul>
  <li>To add variables into the scope of the function, put them between [ and ] on the lambda function. </br>
  Example: 
  ```C++
  int a = 10;
  FunctionManager::Register<void>("Example", [&a]() -> void { std::cout << a << std::endl });</i>
  ```
  </li>

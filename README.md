# FunctionManager
<h1>Usage</h1>
<p><b>1. Usage for fman.h + fman.cpp</p></b>
<p><b>The functions only have one type, which is <i>functype</i>, defined in fman.h</p></b>
<p><i>FunctionManager::Register("FunctionName", []() -> functype { /*function code*/ }, bOverwrite /*overwrite function with same name*/)</p></i>
<p>OBS: bOverwrite is defined as true by default in both cases</p>
<p>Example:</p></br>
<p><i>FunctionManager::Register("ExampleFunc", []() -> functype { return 1337; }, false);</p></i>
<p><i>FunctionManager::Call("ExampleFunc");</p></i>
</br>
</br>
<p><b>2. Usage for fman.hpp</p></b>
<p><b>The functions can have any type, everything is defined on this single file (no need of fman.cpp)</p></b>
<p>OBS: bOverwrite is defined as true by default in both cases</p>
<p><i>FunctionManager::Register<type_here>("FunctionName", []() -> type_here { /*function code*/ }, bOverwrite /*overwrite function with same name*/)</p></i>
<p>Example:</p></br>
<p><i>FunctionManager::Register<std::string>("ExampleFunc", []() -> std::string { return "hello"; }, false);</p></i>
<p><i>FunctionManager::Call<std::string>("ExampleFunc");</p></i>

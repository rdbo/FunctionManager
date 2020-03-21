#pragma once
#include <iostream>
#include <functional>
#include <map>
#define BAD_FUNCTION NULL
#define BAD_RETURN 0
typedef int functype;

namespace FunctionManager
{
	extern std::map<std::string, std::function<functype()>> function_arr;
	bool Register(std::string strName, std::function<functype()> func, bool overwrite = true);
	functype Call(std::string strName);
}
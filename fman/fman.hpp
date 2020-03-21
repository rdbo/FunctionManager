#pragma once
#include <iostream>
#include <functional>
#include <unordered_map>
#define BAD_FUNCTION NULL
#define BAD_RETURN 0

//FunctionManager
namespace FunctionManager
{
	template <class functype>
	static std::unordered_map<std::string, std::function<functype()>> function_arr;
	template <class functype>
	bool Register(std::string strName, std::function<functype()> func, bool overwrite = true);
	template <class functype>
	functype Call(std::string strName);
}

//Functions

template <class functype>
bool FunctionManager::Register(std::string strName, std::function<functype()> func, bool overwrite)
{
	if (!overwrite && function_arr<functype>.count(strName) > 0) return false;
	function_arr<functype>[strName] = func;
	return true;
}

template <class functype>
functype FunctionManager::Call(std::string strName)
{
	if (function_arr<functype>.count(strName) == 0 || function_arr<functype>[strName] == BAD_FUNCTION) return (functype)BAD_RETURN;

	try
	{
		functype ret = (functype)function_arr<functype>[strName]();
		return ret;
	}

	catch (const std::exception & e)
	{
		function_arr<functype>[strName] = BAD_FUNCTION;
		return (functype)BAD_RETURN;
	}
}
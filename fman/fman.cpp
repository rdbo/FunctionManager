#include "fman.h"

std::unordered_map<std::string, std::function<functype()>> FunctionManager::function_arr;

bool FunctionManager::Register(std::string strName, std::function<functype()> func, bool overwrite)
{
	if (!overwrite && function_arr.count(strName) > 0) return false;
	function_arr[strName] = func;
	return true;
}

functype FunctionManager::Call(std::string strName)
{
	if (function_arr.count(strName) == 0 || function_arr[strName] == BAD_FUNCTION) return BAD_RETURN;

	try
	{
		functype ret = function_arr[strName]();
		return ret;
	}

	catch (const std::exception& e)
	{
		function_arr[strName] = BAD_FUNCTION;
		return BAD_RETURN;
	}
}
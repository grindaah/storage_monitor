#pragma once

#include <iostream>

class pathutils
{
public:
	pathutils(std::wstring ss) :
		_path(ss)
	{
	}
private:
	std::wstring _path;
};


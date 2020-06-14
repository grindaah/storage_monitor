#pragma once

#include <string>
#include <iostream>

using namespace std;

class filerecord
{
public:
	filerecord(wstring nm, wstring fp) :
		name(nm),
		fullpath(fp)
	{};
	wstring name;
	wstring fullpath;

	/*inline bool operator< ( const filerecord& rhs)
	{
		return this->name < rhs.name;
	}*/
	//friend bool operator< ()

	bool operator == (const filerecord& right)
	{
		return this->name == right.name;
	}
};

inline bool operator< (const filerecord& lhs, const filerecord& rhs)
{
	return lhs.name < rhs.name;
}

inline wostream& operator<< (wostream& os, const filerecord& fr)
{
	os << fr.fullpath.c_str() <<'\\' << fr.name.c_str();
	return os;
}
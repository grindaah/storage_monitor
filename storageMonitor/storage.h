#pragma once

#include <string>

#include <vector>
#include "diskutils.h"
#include "filerecord.h"

using namespace std;

class storage_fabric;

class storage
{
public:
	friend class storage_fabric;

	void scan();
	void printout();

	list < filerecord > get_files() const;

	storage(wstring name, wstring path) :
		_name(name),
		_path(path),
		_display_name(name)
	{
		_accessible = disk_utils::checkPath(path.c_str());
		;
	};
	storage(wstring name, wstring path, wstring display_name) :
		_name(name),
		_path(path),
		_display_name(display_name)
	{
		_accessible = disk_utils::checkPath(path.c_str());
	};

private:


	wstring _name;
	wstring _display_name;
	wstring _path;

	bool _accessible;

	list< filerecord > files;
};


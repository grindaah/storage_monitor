#pragma once

#include <map>
#include <list>
#include <string>
#include "storage.h"

using namespace std;

class storageanalyser
{
	typedef map < filerecord, storage >::iterator storage_it;

	vector <storage> storages;

	map < filerecord, storage > _files_warehouse;
	list < filerecord > duplicates;

public:
	void add(const storage& st);

	void analyse();
	list <filerecord > get_duplicates();
	void print_duplicates();
};


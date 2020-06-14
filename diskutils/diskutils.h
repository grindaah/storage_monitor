#pragma once

#include <string>
#include <list>
#include <tuple>

#include <windows.h>

#include "filerecord.h"

using namespace std;

namespace disk_utils
{
	LPCWSTR getLPCWSTR(const string);

	list< string > listDirectory(LPCWSTR path);
	list< filerecord > listDirectoryRecursive(LPCWSTR path);

	bool checkPath(LPCWSTR path);
}

//string patchPath(string path);

//list< tuple < string, string > > listDirectoryTree(string path);

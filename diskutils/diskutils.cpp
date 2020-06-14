
#include "pch.h"
#include "framework.h"

#include <list>
#include <vector>
#include <string>
#include <iostream>

#include <windows.h>
#include "filerecord.h"

using namespace std;

namespace disk_utils
{
	LPCWSTR getLPCWSTR(const wstring str)
	{
		//str.
		return L"11";
	}

	wstring cutWSTR(LPCWSTR str)
	{
		wstring s(str);
		// safe cutting off 2 last symbols (if exist)
		if (s.length() > 1)
		{
			s.erase(s.length() - 2, 2);
		}
		return s;
	}

	template<class T> bool isDotOrDotDot(const T* s)
	{
		if (s[0] == T('.'))
		{
			if (s[1] == T('\0')) return true; // .
			if (s[1] == T('.') && s[2] == T('\0')) return true; // ..
		}
		return false;
	}

	list <string> listDirectory(LPCWSTR path)
	{
		list <string> result;
		WIN32_FIND_DATA findData;
		HANDLE hFind = FindFirstFile(path, &findData);
		char cFilename[260];
		char defChar = ' ';

		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				WideCharToMultiByte(CP_ACP, 0, findData.cFileName, -1, cFilename, 260, &defChar, NULL);
				if ((FILE_ATTRIBUTE_DIRECTORY & findData.dwFileAttributes) != FILE_ATTRIBUTE_DIRECTORY)
				{
					result.push_back(string(cFilename));
				}
				
			} while (FindNextFile(hFind, &findData));
		}
		return result;
	}

	//TODO: vector < filerecord > listDirectoryRecursive(LPCWSTR path, customFilter)
	// customFilter: size, lastDate, initDate....

	list < filerecord > listDirectoryRecursive(LPCWSTR path)
	{
		list <filerecord > result;

		WIN32_FIND_DATA findData;
		HANDLE hFind = FindFirstFile(path, &findData);

		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				if (isDotOrDotDot(findData.cFileName))
				{
					continue;
				}
				if ((FILE_ATTRIBUTE_DIRECTORY & findData.dwFileAttributes) == FILE_ATTRIBUTE_DIRECTORY)
				{
					wstring dirToScan(cutWSTR(path));
					wstring dir2(findData.cFileName);
					dirToScan = dirToScan.append(L"\\").append(dir2).append(L"\\*");

					result.splice(result.end(), listDirectoryRecursive(dirToScan.c_str()));
					//result.emplace_back(std::forward<vector <filerecord> >( ));
				} else if (findData.nFileSizeLow > (1024*1024*300) || findData.nFileSizeHigh > 0)
				{
					result.push_back(filerecord(findData.cFileName, cutWSTR(path)));
				}
			} while (FindNextFile(hFind, &findData));
		}
		return result;
	}

	bool checkPath(LPCWSTR path)
	{
		WIN32_FIND_DATA findData;
		HANDLE hFind = FindFirstFile(path, &findData);

		return hFind != INVALID_HANDLE_VALUE;
	}
}



// TODO: Rayon#9 test
// TODO: duplicate analysis

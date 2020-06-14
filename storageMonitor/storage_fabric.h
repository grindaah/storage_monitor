#pragma once

#include <memory>
#include "storage.h"
#include "diskutils.h"

class storage_fabric
{
public:
	storage_fabric() = delete;
	storage_fabric(storage_fabric&) = delete;

	static int counter;

	static shared_ptr<storage> create_storage(wstring path, wstring description)
	{
		if (disk_utils::checkPath(path.c_str())) {
			counter++;
			wstring nm(L"n" + counter);
			return std::make_shared<storage>(storage(nm, path, description));
		}
		return nullptr;
	}
};

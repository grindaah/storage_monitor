#include "storage.h"

void storage::scan()
{
	this->files = disk_utils::listDirectoryRecursive(_path.c_str());
}

void storage::printout()
{
	std::wcout << "storage [" << this->_display_name.c_str() << "] contains:" << std::endl;
	for (const auto& r : this->files)
	{
		std::wcout << r << std::endl;
	}
}

list <filerecord> storage::get_files() const
{
	return this->files;
}
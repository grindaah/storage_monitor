#include "storageanalyser.h"

void storageanalyser::add(const storage& st) 
{
	this->storages.push_back(st);
}

void storageanalyser::analyse()
{
	for (const auto& sts : this->storages)
	{
		for (const auto& r : sts.get_files())
		{
			pair< storage_it, bool > insert_result = this->_files_warehouse.insert(std::make_pair(r, sts));
			if (!insert_result.second)
			{
				this->duplicates.push_back(r);
			}
		}
	}
	std::cout << "files warehouse contains: " << this->_files_warehouse.size();
}

list <filerecord > storageanalyser::get_duplicates()
{
	return this->duplicates;
}

void storageanalyser::print_duplicates()
{
	for (const auto& d : this->duplicates)
	{
		std::wcout << d << std::endl;
	}
}
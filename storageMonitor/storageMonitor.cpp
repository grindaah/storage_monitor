// storageMonitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "storage.h"
#include "storageanalyser.h"
#include "storage_fabric.h"
//#include "diskutils.h"


int main()
{
    std::cout << "Hello World of disks!\n";

    auto str1 = storage_fabric::create_storage(L"F:\\torrents\\*", L"asus n76, n1 storage");

    if (str1)
    {
        str1->scan();
    }
    //storage str1(L"n1", L"F:\\torrents\\*", L"asus n76, n1 storage");
    //storage str2(L"n2", L"G:\\movies\\*", L"seagate black mamba 1TB");
    //storage str3(L"n3", L"I:\\movies\\*", L"Transcend orange avenger 512 MB");

    
    //str2.scan();
    //str3.scan();

    std::cout << "str1 contains:" << str1->get_files().size() << std::endl;
    //std::cout << "str2 contains:" << str2.get_files().size() << std::endl;
    //std::cout << "str3 contains:" << str3.get_files().size() << std::endl;


    storageanalyser storageAnalyser;
    storageAnalyser.add(*str1);
    //storageAnalyser.add(str2);
    //storageAnalyser.add(str3);

    storageAnalyser.analyse();
    storageAnalyser.print_duplicates();

    /*
    --- initial implementation with diskutils
    LPCWSTR mpath(L"D:\\*");
    std::list <string> _files;
    _files = disk_utils::listDirectory(mpath);
    if (!_files.empty())
    {
        do {
            cout << _files.back() << endl;
            _files.pop_back();
        } while (!_files.empty());
    }
    //_files = disk_utils::listDirectory(mpath);
    char kp;
    std::cin >> kp;*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

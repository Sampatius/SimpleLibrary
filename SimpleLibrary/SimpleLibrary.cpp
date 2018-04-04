// SimpleLibrary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Library.h"
#include <Windows.h>
#include <ShlObj.h>
#include <tchar.h>


int main()
{
	
	Library lib;

	TCHAR myPath[MAX_PATH];

	std::string filePath;

	SHGetSpecialFolderPath(0, myPath, CSIDL_DESKTOP, FALSE);

	filePath = myPath;

	filePath += "\\test.txt";

	lib.loadData(filePath);

	lib.sortByAuthor();

	lib.printBooks();
	
    return 0;
}


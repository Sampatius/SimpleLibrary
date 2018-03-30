#include "stdafx.h"
#include "Library.h"
#include "Book.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>


Library::Library()
{
}


Library::~Library()
{
}

void Library::initLibrary()
{
}

void Library::loadData(std::string path)
{
	std::string line;
	std::ifstream dataFile(path);

	std::string delimeter = "||";

	std::string name, author;
	int pub_year;
	bool borrowed;
	
	size_t pos;
	std::string token;

	if (dataFile.is_open()) {
		while (std::getline(dataFile, line)) {
			std::istringstream lineFromFile(line);
			lineFromFile >> name >> author >> pub_year >> borrowed;
			Book book(name, author, pub_year, borrowed);
			books.push_back(book);
		}
	}
}

void Library::saveData()
{
}

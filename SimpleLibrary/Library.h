#pragma once
#include "Book.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

class Library
{
public:
	Library();
	~Library();

	void initLibrary();
	void loadData(std::string path);
	void saveData();

	void printBooks();

	Book getBook(int position);
	Book getBook(std::string bookName);

private:
	std::vector<Book> books;
};


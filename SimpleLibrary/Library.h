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
	void saveData(std::string path);

	void printBooks();

	Book getBook(int position);
	Book getBook(std::string bookName);
	Book getBook(std::string authorName);

private:
	std::vector<Book> books;
};


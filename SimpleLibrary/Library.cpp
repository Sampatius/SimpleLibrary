#include "stdafx.h"
#include "Library.h"


Library::Library()
{
}


Library::~Library()
{
}

void Library::initLibrary()
{
}

/*	Load data from text file to vector. Data must be in format
	BOOK_NAME|AUTHOR_NAME|PUBLISHING_YEAR|BORROWED
*/
void Library::loadData(std::string path)
{
	std::string line;
	std::ifstream dataFile(path);

	std::string delimeter = "||";

	std::string name, author;
	int pub_year;
	bool borrowed;

	if (dataFile.is_open()) {
		while (std::getline(dataFile, line)) {
			std::istringstream lineFromFile(line);
			lineFromFile >> name >> author >> pub_year >> borrowed;
			Book book(name, author, pub_year, borrowed);
			books.push_back(book);
		}
	}
}

void Library::saveData(std::string path)
{
	std::string name, author;
	int pub_year;
	bool borrowed;

	std::string line;
	std::ofstream dataFile(path);

	for (auto& book : books) {
		name = book.getName();
		author = book.getAuthor();
		pub_year = book.getPubYear();
		borrowed = book.getBorrowed();

		line = name + "||" + author + "||" + std::to_string(pub_year) + "||" + std::to_string(borrowed) + "\n";

		dataFile << line;
	}
}

void Library::printBooks()
{
	for (auto& book : books) {
		std::cout << book.getName() << " || " << book.getAuthor() << " || " << book.getPubYear() << " || " << book.getBorrowed();
	}
}

Book Library::getBook(int position)
{
	return books[position];
}

Book Library::getBook(std::string bookName)
{
	for (auto& book : books) {
		if (book.getName() == bookName) {
			return book;
		}
	}
}

Book Library::getBook(std::string authorName) {

}

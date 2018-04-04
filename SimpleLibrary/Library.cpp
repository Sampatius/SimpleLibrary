#include "stdafx.h"
#include "Library.h"


Library::Library()
{
}


Library::~Library()
{
}

/*	Load data from text file to vector. Data must be in format
	BOOK_NAME||AUTHOR_NAME||PUBLISHING_YEAR||BORROWED||
*/
void Library::loadData(std::string path)
{
	std::ifstream dataFile(path);
	std::string delimeter = "||";
	std::string line;
	std::string tokens[4];

	std::string bookName, authorName;
	int pubYear;
	bool borrowed;

	if (dataFile.is_open()) {
		while (std::getline(dataFile, line)) {
			auto start = 0U;
			auto end = line.find(delimeter);
			int pos = 0;

			while (end != std::string::npos) {
				tokens[pos] = line.substr(start, end - start);
				start = end + delimeter.length();
				end = line.find(delimeter, start);
				pos++;
			}

			bookName = tokens[0];
			authorName = tokens[1];
			pubYear = std::stoi(tokens[2]);

			if (tokens[3] == "1") {
				borrowed = true;
			}
			else {
				borrowed = false;
			}

			Book book(bookName, authorName, pubYear, borrowed);
			books.push_back(book);
		}
		dataFile.close();
	}
}

/* Save data to file in format BOOK_NAME||AUTHOR_NAME||PUBLISHING_YEAR||BORROWED|| */
void Library::saveData(std::string path)
{
	std::string name, author, bookBorrowed;
	int pub_year;
	bool borrowed;

	std::string line;
	std::ofstream dataFile(path);

	for (auto& book : books) {
		name = book.getName();
		author = book.getAuthor();
		pub_year = book.getPubYear();
		borrowed = book.getBorrowed();

		bookBorrowed = (borrowed) ? "1" : "0";

		line = name + "||" + author + "||" + std::to_string(pub_year) + "||" + bookBorrowed + "\n";

		dataFile << line;
	}
}

/* Print books, mainly used for debugging at the moment*/
void Library::printBooks()
{
	std::string borrowed;

	for (auto& book : books) {
		borrowed = (book.getBorrowed()) ? "Borrowed" : "Available";
		std::cout << book.getName() << " || " << book.getAuthor() << " || " << book.getPubYear() << " || " << borrowed << std::endl;
	}
}

/* Get book by it's position in vector */
Book Library::getBook(int position)
{
	return books[position];
}

/* Get book from vector by it's name */
Book Library::getBook(std::string bookName)
{
	for (auto& book : books) {
		if (book.getName() == bookName) {
			return book;
		}
	}
}

/* Get multiple books from vector by author's name */
std::vector<Book> Library::getBooksByAuthor(std::string authorName)
{
	std::vector<Book> authorVector;
	for (auto& book : books) {
		if (book.getAuthor() == authorName) {
			authorVector.push_back(book);
		}
	}
	return authorVector;
}

/* Sort by name */
void Library::sortByName()
{
	std::sort(books.begin(), books.end(), [](Book& lhs, Book& rhs) { return lhs.getName() < rhs.getName(); });
}

/* Sort by author */
void Library::sortByAuthor()
{
	std::sort(books.begin(), books.end(), [](Book& lhs, Book& rhs) { return lhs.getAuthor() < rhs.getAuthor(); });
}

/* Sort by year */
void Library::sortByYear()
{
	std::sort(books.begin(), books.end(), [](Book& lhs, Book& rhs) { return lhs.getPubYear() < rhs.getPubYear(); });
}

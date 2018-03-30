#pragma once
#include <string>

class Book
{
public:
	Book();
	Book(std::string name) { name_ = name; }
	Book(std::string name, std::string author) { name_ = name, author_ = author; }
	Book(std::string name, std::string author, int pub_year) { name_ = name, author_ = author, pub_year_ = pub_year; }
	Book(std::string name, std::string author, int pub_year, bool borrowed) { name_ = name, author_ = author, pub_year_ = pub_year, borrowed_ = borrowed; }
	~Book();

	inline std::string getName() { return name_; }
	inline std::string getAuthor() { return author_; }
	inline int getPubYear() { return pub_year_; }
	inline bool getBorrowed() { return borrowed_; }

	inline std::string setName(std::string name) { name_ = name; }
	inline std::string setAuthor(std::string author) { author_ = author; }
	inline int setPubYear(int pub_year) { pub_year_ = pub_year; }
	inline int setBorrowed(bool borrowed) { borrowed_ = borrowed; }

private:
	std::string name_;
	std::string author_;
	int pub_year_;
	bool borrowed_;
};


#pragma once
class Book
{
public:
	Book();
	Book(char* name) { name_ = name; }
	Book(char* name, char* author) { name_ = name, author_ = author; }
	Book(char* name, char* author, int pub_year) { name_ = name, author_ = author, pub_year_ = pub_year; }
	~Book();

	inline char* getName() { return name_; }
	inline char* getAuthor() { return author_; }
	inline int getPubYear() { return pub_year_; }
	inline bool getBorrowed() { return borrowed_; }

	inline char* setName(char* name) { name_ = name; }
	inline char* setAuthor(char* author) { author_ = author; }
	inline int setPubYear(int pub_year) { pub_year_ = pub_year; }
	inline int setBorrowed(bool borrowed) { borrowed_ = borrowed; }

private:
	char* name_;
	char* author_;
	int pub_year_;
	bool borrowed_;
};


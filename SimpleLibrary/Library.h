#pragma once
class Library
{
public:
	Library();
	~Library();

	void initLibrary();
	void loadData(std::string path);
	void saveData();

private:
	std::vector<Book> books;
};


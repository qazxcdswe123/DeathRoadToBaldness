#ifndef READER_H
#define READER_H

#include <iostream>

extern const int maxBorrow = 5;
class Reader
{
private:
	bool deleteFlag = false;
	int id;
	std::string name;
	int bookBorrowed[maxBorrow];

public:
	Reader() = default;
	Reader(int id, std::string name);
	virtual ~Reader() = default;

	// getter setter
	void setId(int id);
	void setName(std::string name);
	void setDeleteFlag(bool deleteFlag);
	void setBookBorrowed(int bookBorrowed[maxBorrow]);
	int getId() const;
	std::string getName() const;
	bool getDeleteFlag() const;

	// function
	void borrowBook(int bookId);
	int returnBook(int bookId);
	void print();
};


#endif

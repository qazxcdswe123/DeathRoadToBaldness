#ifndef BookS_H
#define BookS_H

#include <iostream>

class Book
{
private:
	bool deleteFlag = false; // true if the book is deleted
	int id; // id of the book 
	std::string title;
	bool onShelf; // true if the book is on the shelf

public:
	Book() = default;
	Book(int id, std::string title, bool onshelf);
	virtual ~Book() = default;

	// setter
	void setId(int);
	void setTitle(std::string);
	void setOnshelf(bool);
	void setDeleteFlag(bool);
	// getter
	int getId() const;
	std::string getTitle() const;
	bool getOnshelf() const;
	bool getDeleteFlag() const;

	// function
	void deleteBook();
	void addBook(int id, std::string title, bool onshelf);
	bool canBorrowThisBook();
	void returnBook();
	void printStored();
};

#endif // BookS_H

#include <iomanip>
#include "books.h"

Book::Book (int id, std::string title, bool onShelf)
{
	this->id = id;
	this->title = title;
	this->onShelf = onShelf;
}

std::string Book::getTitle() const {
	return title;
}

// start getter setter
int Book::getId () const {
	return id;
}

bool Book::getOnshelf () const {
	return onShelf;
}

bool Book::getDeleteFlag () const {
	return deleteFlag;
}

void Book::setId (int num) {
	id = num;
}

void Book::setTitle(std::string newTitle) {
	title = newTitle;
}

void Book::setOnshelf(bool newOnShelf) {
	onShelf = newOnShelf;
}

void Book::setDeleteFlag(bool newDeleteFlag) {
	deleteFlag = newDeleteFlag;
}

// finish getter setter


void Book::deleteBook () {
	this->deleteFlag = true;
}

void Book::addBook (int id, std::string title, bool onShelf) {
	this->id = id;
	this->title = title;
	this->onShelf = onShelf;
}

bool Book::canBorrowThisBook () {
	return onShelf;
}

void Book::returnBook () {
	this->onShelf = true;
}

void Book::printStored () {
	std::cout << std::setw(5) << "ID: " << id << std::endl;
	std::cout << std::setw(5) << "Title: " << title << std::endl;
	std::cout << std::setw(5) << "On Shelf: " << onShelf << std::endl;
	std::cout << std::setw(5) << "Delete Flag: " << deleteFlag << std::endl;
}

#include <iomanip>

#include "reader.h"

// getter and setter
std::string Reader::getName () const {
	return name;
}

int Reader::getId () const {
	return id;
}

bool Reader::getDeleteFlag () const {
	return deleteFlag;
}




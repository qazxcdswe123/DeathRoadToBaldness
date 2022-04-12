#include "String.h"
#include <cstring>

String::String(const char* str)
{
	if (str == nullptr)
	{
		m_data = nullptr;
	}
	else
	{
		int length = strlen(str);
		m_data = new char[length + 1];
		strcpy(m_data, str);
		m_data[length] = '\0';
	}
}

String::~String()
{
	delete[] m_data;
}

String::String(const String& other)
{
	m_data = new char[strlen(other.m_data) + 1];
	strcpy(m_data, other.m_data); // will copy the terminate character
}

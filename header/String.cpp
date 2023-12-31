#include <iostream>
#include "String.h"

String::String(const char* rhs)
{
	size_ = strlen(rhs);
	str = new char[size_ + 1];
	strcpy(str, rhs);
}

String::String(const String& rhs)
{
	size_ = rhs.size_;
	str = new char[size_ + 1];
	strcpy(str, rhs.str);
	std::cout << "Call constructor" << std::endl;
}

String::String(String&& rhs)
{
	str = rhs.str;
	size_ = rhs.size_;
	rhs.str = nullptr;
}

String::~String()
{
	delete[] str;
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs)
		return *this;
	delete[] str;
	size_ = rhs.size_;
	str = new char[size_+1];
	strcpy(str, rhs.str);
	return *this;
}

String& String::operator=(const char *rhs)
{
	delete[] str;
	size_ = strlen(rhs);
	str = new char[size_ + 1];
	strcpy(str, rhs);
	return *this;
}

String& String::operator=(String&& rhs)
{
	if (this == &rhs)
		return *this;
	delete[] str;
	str = rhs.str;
	size_ = rhs.size_;
	rhs.str = nullptr;
	return *this;
}

String& String::operator+=(const String& rhs)
{
	char* newStr = new char[size_ + rhs.size_ + 1];
	copy(0, newStr, str);
	copy(size_, newStr, rhs.str);
	delete[] str;
	str = newStr;
	size_ += rhs.size_;
	return *this;
}

String& String::operator+=(const char *rhs)
{
	size_t strSize = strlen(rhs);
	char* newStr = new char[size_ + strSize + 1];
	copy(0, newStr, str);
	copy(size_, newStr, rhs);
	delete[] str;
	size_ += strSize;
	str = newStr;
	return *this;
}

String String::operator+(const String& rhs)
{
	String newStr = *this;
	newStr += rhs;
	return newStr;
}

char& String::operator[](const size_t index)
{
	return str[index];
}

char String::operator[](size_t index) const
{
	return str[index];
}

size_t String::strlen(const char* str)
{
	char c = str[0];
	size_t size = 0;
	for (size_t i = 1; c != '\0'; ++i)
	{
		++size;
		c = str[i];
	}
	return size;
}

void String::strcpy(char* destination, const char* source)
{
	char c = source[0];
	for (size_t i = 0; c != '\0'; ++i)
	{
		destination[i] = source[i];
		c = source[i];
	}
}

size_t String::length()const
{
	return size_;
}

void String::copy(size_t pozition, char *destination,const char* source)
{
	int j = 0;
	char c = source[0];
	for (size_t i = pozition; c!='\0'; ++i)
	{
		destination[i] = source[j];
		c = source[j];
		++j;
	}
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		out << str[i];
	}
	return out;
}

std::istream& operator>>(std::istream& in, String& s)
{
	//delete[] s.str;
	size_t i = 0;
	char c = 'c';
	for (; c!=' ' && c!='\0'; ++i)
	{
		in >> c;
		s += &c;
	}
	s[i] = '\0';
	return in;
}
#include <iostream>
#include "String.h"

String::String(const char* str)
{
	this->size_ = strlen(str);
	this->str = new char[size_ + 1];
	strcpy(this->str, str);
}

String::String(const String& str)
{
	this->size_ = str.size_;
	this->str = new char[size_ + 1];
	strcpy(this->str, str.str);
	std::cout << "Call constructor" << std::endl;
}

String::~String()
{
	delete[] str;
}

String& String::operator=(const String& str)
{
	if (this == &str)
		return *this;
	delete[] this->str;
	this->size_ = str.size_;
	this->str = new char[size_+1];
	strcpy(this->str, str.str);
	return *this;
}

String& String::operator=(const char *str)
{
	delete[] this->str;
	this->size_ = strlen(str);
	str = new char[size_ + 1];
	strcpy(this->str, str);
	return *this;
}

String& String::operator+=(const String& str)
{
	char* newStr = new char[size_ + str.size_ + 1];
	copy(0, newStr, this->str);
	copy(this->size_, newStr, str.str);
	delete[] this->str;
	this->str = newStr;
	this->size_ += str.size_;
	return *this;
}

String& String::operator+=(const char *str)
{
	size_t strSize = strlen(str);
	char* newStr = new char[size_ + strSize + 1];
	copy(0, newStr, this->str);
	copy(this->size_, newStr, str);
	delete[] this->str;
	this->size_ += strSize;
	this->str = newStr;
	return *this;
}

String String::operator+(const String& str)
{
	String newStr = *this;
	newStr += str;
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

void String::strcpy(char* empty, const char* str)
{
	char c = str[0];
	for (size_t i = 0; c != '\0'; ++i)
	{
		empty[i] = str[i];
		c = str[i];
	}
}

size_t String::length()const
{
	return size_;
}

void String::copy(size_t pozition, char *in,const char* str)
{
	int j = 0;
	char c = str[0];
	for (size_t i = pozition; c!='\0'; ++i)
	{
		in[i] = str[j];
		c = str[j];
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

	return in;
}
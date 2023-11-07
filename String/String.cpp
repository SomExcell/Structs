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
}

String::~String()
{
	delete[] str;
}

String::String(String&& str)
{
	this->str = str.str;
	this->size_ = str.size_;
	str.str = nullptr;
	str.size_ = 0;
}

void String::operator=(const String& str)
{
	delete[] this->str;
	this->size_ = str.size_;
	this->str = new char[this->size_+1];
	strcpy(this->str, str.str);
}

void String::operator=(const char *str)
{
	delete[] this->str;
	this->size_ = strlen(str);
	str = new char[this->size_ + 1];
	strcpy(this->str, str);
}

void String::operator=(String&& str)
{
	delete[] this->str;
	this->str = str.str;
	this->size_ = str.size_;
	str.str = nullptr;
	str.size_ = 0;
}

void String::operator+=(const String& str)
{
	char* newStr = new char[size_ + str.size_ + 1];
	add(0, newStr, this->str);
	add(this->size_, newStr, str.str);
	size_ += str.size_;
	delete[] this->str;
	this->str = newStr;
}

void String::operator+=(const char *str)
{
	int strSize = strlen(str);
	char* newStr = new char[size_ + strSize + 1];
	add(0, newStr, this->str);
	add(this->size_, newStr, str);
	this->size_ += strSize;
	delete[] this->str;
	this->str = newStr;
}

String String::operator+(const String& str)
{
	String newStr;
	newStr.size_ = this->size_ + str.size_;
	newStr.str = new char[size_ + 1];
	add(0, newStr.str, this->str);
	add(this->size_, newStr.str, str.str);
	return newStr;
}

char& String::operator[](const int index)
{
	return str[index];
}

int String::strlen(const char* str)
{
	char c = str[0];
	int size = 0;
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
	for (size_t i = 0; c != '\0'; i++)
	{
		empty[i] = str[i];
		c = str[i];
	}
}

int String::length()
{
	return size_;
}

void String::add(int pozition, char *in,const char* str)
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
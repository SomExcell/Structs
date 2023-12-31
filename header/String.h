#pragma once
#include <iostream>

class String
{
	friend std::istream& operator>>(std::istream& in, String& s);
public:
	String() {};
	String(const char* rhs);
	String(const String& rhs);
	String(String&& rhs);
	~String();
	String& operator=(const String& rhs);
	String& operator=(const char* rhs);
	String& operator=(String&& rhs);
	String operator+(const String& rhs);
	String& operator+=(const String& rhs);
	String& operator+=(const char* rhs);
	char& operator[](const size_t index);
	char operator[](size_t index) const;
	size_t length()const;
private:
	void copy(size_t pozition, char* destination,const char* source);
	size_t strlen(const char* str);
	void strcpy(char* destination, const char* source);
	size_t size_ = 0;
	char* str = nullptr;
};
std::ostream& operator<<(std::ostream& out, const String& str);
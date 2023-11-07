#pragma once

class String
{
public:
	String(const char* str = "");
	String(const String& str);
	~String();
	String(String&& str);
	void operator=(const String& str);
	void operator=(const char* str);
	void operator=(String&& str);
	String operator+(const String& str);
	void operator+=(const String& str);
	void operator+=(const char* str);
	char& operator[](int index);
	int length();
private:
	void add(int pozition, char* in,const char* str);
	int strlen(const char* str);
	void strcpy(char* empty, const char* str);
	char* str;
	int size_;
};
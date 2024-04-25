#ifndef STRING_H_
#define STRING_H_

#include <iostream>

class String
{
	friend std::istream& operator>>(std::istream& in, String& s);
public:
	String() = default;
	String(const char* __s);
	String(const String& __str);
	String(String&& __str);
	~String();

	String& operator=(const String& __str);
	String& operator=(String&& __str);
	String& operator=(char __c);
	String& operator=(const char* __s);

	String& operator+=(const String& __str);
	String& operator+=(const char &__c);
	String& operator+=(const char* __s);

	String operator+(const String& __str);
	String operator+(const char &__c);
	String operator+(const char* __s);

	bool operator<(const String& __str);
	bool operator<(const char* __s);

	bool operator==(const String& __str);
	bool operator==(const char* __s);

	bool operator>(const String& __str);
	bool operator>(const char* __s);

	char& operator[](const size_t &index);
	char operator[](const size_t &index) const;

	size_t size()const;
	size_t length()const;
	size_t capacity()const;

	const char *c_str();

	void clear();

private:
	size_t newCapacity(const size_t &size);
	size_t strlen(const char* str);
	char *strcpy(char* destination, const char* source);
	void copyFrom(const char* source,const size_t &sourceSize);


private:
	const size_t MAX_CAPACITY = INT32_MAX;
	const size_t DEFAULT_CAPACITY = 15;
	size_t capacity_ = 15;
	size_t size_ = 0;
	char* str_ = new char[16]{'\0'};
};
std::ostream& operator<<(std::ostream& out, const String& str);

#endif
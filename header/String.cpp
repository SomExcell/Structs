#include "String.h"

String::String(const char* __str)
{
	copyFrom(__str, strlen(__str));
}

String::String(const String& __str)
{
	copyFrom(__str.str_,__str.size_);
}

String::String(String&& __str)
{
	delete [] str_;
	str_ = __str.str_;
	size_ = __str.size_;
	capacity_ = __str.capacity_;

	__str.size_ = 0;
	__str.capacity_ = 15;
	__str.str_ = new char[__str.capacity_+1];
	__str.str_[0] = '\0';
}

String::~String()
{
	delete[] str_;
}

String& String::operator=(const String& __str)
{
	if (this == &__str)
		return *this;
	clear();
	copyFrom(__str.str_,__str.size_);
	return *this;
}

String& String::operator=(const char *__s)
{
	clear();
	size_t newSize = strlen(__s);
	char* __sCopy = new char[newSize+1];
	strcpy(__sCopy,__s);
	copyFrom(__sCopy,newSize);
	return *this;
}

String& String::operator=(String&& __str)
{
	if (this == &__str)
		return *this;
	delete[] str_;
	str_ = __str.str_;
	size_ = __str.size_;
	capacity_ = __str.capacity_;

	__str.size_ = 0;
	__str.capacity_ = 15;
	__str.str_ = new char[__str.capacity_ + 1];
	__str.str_[0] = '\0';
	return *this;
}

String& String::operator+=(const String& __str)
{
	copyFrom(__str.str_,__str.size_);
	return *this;
}

String& String::operator+=(const char &__c)
{
	char* source = new char[2];
	source[0] = __c; source[1] = '\0';
	copyFrom(source,1);
	return *this;
}

String& String::operator+=(const char *__s)
{
	copyFrom(__s,strlen(__s));
	return *this;
}

String String::operator+(const String& __str)
{
	String newStr = *this;
	newStr += __str;
	return newStr;
}

String String::operator+(const char &__c)
{
	String newStr = *this;
	newStr += __c;
	return newStr;
}

String String::operator+(const char *__s)
{
	String newStr = *this;
	newStr += __s;
	return newStr;
}

bool String::operator<(const String& __str)
{
	return *this < __str.str_;
}

bool String::operator<(const char* __s)
{
	size_t __sSize = strlen(__s);
	for (size_t i = 0; i < size_; i++)
	{
		if(str_[i] > __s[i]){return false;}
		else if(str_[i] < __s[i]){return true;}
	}
	if(size_ < __sSize){return true;}
	return false;
}

bool String::operator==(const String& __str)
{
	if(size_ != __str.size_){return false;}
	return *this == __str.str_;
}

bool String::operator==(const char* __s)
{
	for (size_t i = 0; i < size_; i++)
	{
		if(str_[i] != __s[i]){return false;}
	}
	return true;
}

bool String::operator>(const String& __str)
{
	return *this > __str.str_;
}

bool String::operator>(const char* __s)
{
	size_t __sSize = strlen(__s);
	for (size_t i = 0; i < size_; i++)
	{
		if(str_[i] < __s[i]){return false;}
		else if(str_[i] > __s[i]){return true;}
	}
	if(size_ > __sSize){return true;}
	return false;
}

char& String::operator[](const size_t &index)
{
	return str_[index];
}

char String::operator[](const size_t &index) const
{
	return str_[index];
}

size_t String::size()const
{
	return size_;
}

size_t String::length()const
{
	return size_;
}

size_t String::capacity()const
{
	return capacity_;
}

const char *String::c_str()
{
	return &str_[0];
}

void String::clear()
{
	size_ = 0;
	str_[0] = '\0';
}

size_t String::strlen(const char* str)
{
	size_t size = 0;
	while(str[size]!='\0'){++size;}
	return size;
}

char *String::strcpy(char* destination, const char* source)
{
	char *current = destination;
	while(*source != '\0')
	{
		*current = *source;
		source++,current++;
	}
	*current = '\0';
	return destination;
}

void String::copyFrom(const char* source,const size_t &sourceSize)
{
	size_t newSize = size_ + sourceSize;
	if(capacity_ < newSize)
	{
		newCapacity(newSize);
		char* newStr = new char[capacity_ + 1];
		strcpy(newStr, str_);
		delete[] str_;
		str_ = newStr;
	}
	strcpy(str_ + size_,source);
	size_ = newSize;
}

size_t String::newCapacity(const size_t &size)
{
	size_t newCap = capacity_;
	while(newCap <= size_ && newCap <= MAX_CAPACITY){newCap*=2;}
	if(newCap > MAX_CAPACITY){newCap = MAX_CAPACITY;}
	capacity_ = newCap;
	return newCap;
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
	s.clear();
	char c;
	in >> c;
	for(;c != '\0' && c != '\n' && c != ' ';)
	{
		s+=c;
		in.get(c);
	}
	return in;
}
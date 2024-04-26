#include "String.h"

String::String(const char* __str)
{
	append(__str, strlen(__str));
}

String::String(const String& __str)
{
	append(__str.str_,__str.size_);
}

String::String(String&& __str)
{
	String copy;
	swap(copy,__str);
	swap(*this,copy);
}

String::~String()
{
	delete[] str_;
}

String& String::operator=(const String& __str)
{
	if (this == &__str)
		return *this;
	operator=(__str.str_);
	return *this;
}

String& String::operator=(const char *__s)
{
	size_t __sSize = strlen(__s);
	char* __sCopy = new char[__sSize+1]{'\0'};
	strcpy(__sCopy,__s);
	clear();
	append(__sCopy,__sSize);
	delete[] __sCopy;
	return *this;
}

String& String::operator=(String&& __str)
{
	if (this == &__str)
		return *this;
	String copy;
	swap(copy,__str);
	swap(*this,copy);
	return *this;
}

String& String::operator+=(const String& __str)
{
	operator+=(__str.str_);
	return *this;
}

String& String::operator+=(const char &__c)
{
	char* source = new char[2];
	source[0] = __c; source[1] = '\0';
	append(source,1);
	delete[]source;
	return *this;
}

String& String::operator+=(const char *__s)
{
	size_t __sSize = strlen(__s);
	char* __sCopy = new char[__sSize+1]{'\0'};
	strcpy(__sCopy,__s);
	append(__sCopy,__sSize);
	delete[] __sCopy;
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

bool String::operator<(const std::string& __str)
{
	return *this < __str.c_str();
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

bool String::operator==(const std::string& __str)
{
	if(size_ != __str.size()){return false;}
	return *this == __str.c_str();
}

bool String::operator==(const char* __s)
{
	for (size_t i = 0; i < size_; i++)
	{
		if(str_[i] != __s[i]){return false;}
	}
	return true;
}

bool String::operator!=(const String& __str)
{
	return !(*this == __str);
}

bool String::operator!=(const std::string& __str)
{
	return !(*this == __str);
}

bool String::operator!=(const char* __s)
{
	if(size_ != strlen(__s)){return true;}
	return !(str_ == __s);
}

bool String::operator>(const String& __str)
{
	return *this > __str.str_;
}

bool String::operator>(const std::string& __str)
{
	return *this > __str.c_str();
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

size_t String::max_size()const
{
	return MAX_CAPACITY;
}

const char *String::c_str()
{
	return &str_[0];
}

char *String::data()
{
	return &str_[0];
}

void String::clear()
{
	size_ = 0;
	str_[0] = '\0';
}

void String::swap(String& __s)
{
	swap(*this,__s);
}

size_t String::newCapacity(const size_t &size)
{
	if(size>MAX_CAPACITY){std::cerr << "MAXIMUM STRING SIZE EXCEEDED";}
	size_t newCap = capacity_;
	while(newCap <= size && newCap <= MAX_CAPACITY){newCap*=2;}
	if(newCap > MAX_CAPACITY){newCap = MAX_CAPACITY;}
	capacity_ = newCap;
	
	char *newStr_ = new char[capacity_ + 1]{'\0'};
	strcpy(newStr_,str_);
	delete []str_;
	str_ = newStr_;

	return newCap;
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

void String::append(const char* source,const size_t &sourceSize)
{
	size_t newSize = size_ + sourceSize;
	if(capacity_ < newSize){newCapacity(newSize);}

	strcpy(str_ + size_,source);
	size_ = newSize;
}

void String::swap(String& lhs,String& rhs)
{
	char *tmpStr_ = lhs.str_;
	lhs.str_ = rhs.str_;
	rhs.str_ = tmpStr_;

	size_t tmpSize_ = lhs.size_;
	lhs.size_ = rhs.size_;
	rhs.size_ = tmpSize_;

	size_t tmpCap_ = lhs.capacity_;
	lhs.capacity_ = rhs.capacity_;
	rhs.capacity_ = tmpCap_;
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	for (size_t i = 0; i < str.size(); i++)
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
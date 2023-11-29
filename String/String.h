#pragma once

class String
{
	friend std::istream& operator>>(std::istream& in, String& s);
public:
	String(const char* str = "");
	String(const String& str);
	~String();
	String& operator=(const String& str);
	String& operator=(const char* str);
	String operator+(const String& str);
	String& operator+=(const String& str);
	String& operator+=(const char* str);
	char& operator[](const size_t index);
	char operator[](size_t index) const;
	size_t length()const;
private:
	void copy(size_t pozition, char* in,const char* str);
	size_t strlen(const char* str);
	void strcpy(char* empty, const char* str);
	char* str = nullptr;
	size_t size_ = 0;
};
std::ostream& operator<<(std::ostream& out, const String& str);
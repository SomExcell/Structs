#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "String.h"

int main()
{
	String x = "avs";
	x += x;
	x += "bbb";
	String b = "asdsa";
	String a;
	a = x + b;
	std::cout << a << std::endl;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"string.h"
sss::string::string() 
:_str(new char[1]{'\0'})
,_size(0)
,_capacity(0)
{}

sss::string::string(const char* arr) 
	:_size(strlen(arr))
{
	_capacity = _size;
	_str = new char[_size + 1];
	strcpy(_str,arr);
}

char& sss::string::operator[](size_t i) {
	assert(i<=_size);
	return _str[i];
}

std::ostream& sss::operator<<(std::ostream& out, sss::string& a) {
	size_t i = 0;
	while (a[i] != '\0') {
		out << a[i];
		i++;
	}
	return out;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"string.h"

mystring::string::string(mystring::string& a) 
:_str(new char[a._capacity+1])
,_capacity(a._capacity)
,_size(a._size)
{
	strcpy(_str,a._str);
}

mystring::string::string() 
	:_size(0)
	,_capacity(0)
{
	_str = new char[1];
	(*_str) = '\0';
}

mystring::string::string(const char* str) {
	size_t len = ::strlen(str);
	_size = len;
	_str = new char[len + 1];
	strcpy(_str,str);
	_size = len;
	_capacity = len;
}

char* mystring::string::c_str() {
	return _str;
}

std::ostream& mystring::operator<<(std::ostream& out, mystring::string q1) {
	size_t i = 0;
	for (; i < q1._size;i++) {
		out << *(q1._str + i);
	}
	return out;
}

void mystring::string::operator+(char ch) {
	if (_size==_capacity) {
		size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
		space(newcapacity);
		_capacity = newcapacity;
	}
	*(_str + _size) = ch;
	*(_str + _size + 1) = '\0';
	++_size;
}

void mystring::string::space(size_t n) {
	char* pa = _str;
	_str = new char[n + 1];
	strcpy(_str,pa);
}

void mystring::string::append(const char* str) {
	size_t len = strlen(str);
	if (_size+len>=_capacity) {
		size_t newcapacity = _capacity == 0 ? len : _size + len;
		space(newcapacity);
		_capacity = newcapacity;
	}
	size_t i = _size, j = 0;
	for (; j < len;j++) {
		*(_str + i) = *(str + j);
		++i;
	}
	*(_str + i) = '\0';
	_size += len;
}

void mystring::string::insert(size_t pos,char ch) {
	assert(pos+1<=_size);
	if (_size>=_capacity) {
		size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
		space(newcapacity);
		_capacity = newcapacity;
	}
	*(_str + _size + 1) = '\0';
	size_t pp = _size - 1;
	while (pp>=pos) {
		*(_str+pp+1) = *(_str+pp);
		--pp;
	}
	++_size;
	*(_str + pos) = ch;
}

void  mystring::string::insert(size_t pos,const char* str) {
	assert(pos+1<=_size);
	size_t len = strlen(str);
	if (_size==_capacity) {
		size_t newcapacity = _size + len < 2 * _capacity ? 2 * _capacity : _size + len;
		space(newcapacity);
	}
	char* pa = new char[_size - pos + 1];
	_size += len;
	strcpy(pa,_str+pos);
	strcpy(_str+pos,str);
	strcpy(_str + pos + len, pa);
	delete[] pa;
}

mystring::string::~string() {
	delete[] _str;
	_str = nullptr;
}

char& mystring::string::operator[](size_t i){
	return *(_str + i);
}

std::istream& mystring::operator>>(std::istream& in, mystring::string& s) {
	s.clear();
	char ch = in.get();
	while (ch!='\n'&&ch!=' ') {
		s + ch;
		ch = in.get();
	}
	return in;
}

void mystring::string::clear() {
	_size = 0;
	*(_str + 0) = '\0';
}
std::istream& mystring::Getline(std::istream& in, mystring::string& s, char ch) {
	s.clear();
	char cha = in.get();
	while (cha!=ch) {
		s + cha;
		cha = in.get();
	}
	return in;
}
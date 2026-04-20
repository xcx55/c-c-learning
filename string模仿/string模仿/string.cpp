#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include"string.h"


s::string::string()
	:_str(new char[1]{'\0'})
	, _size(0)
	, _capacity(0)
{}

s::string::string(const char* arr) 
:_size(strlen(arr))//构建this指针，且以声明顺序第一次初始化
{
	_capacity = _size;
	_str = new char[_size + 1];
	strcpy(_str,arr);
}

const char* s::string::c_str() {
	return this->_str;
}

const char& s::string::operator[](size_t i) {
	assert(i<_size);
	return *(_str + i);
}

s::string::~string() {
	delete[] _str;
}
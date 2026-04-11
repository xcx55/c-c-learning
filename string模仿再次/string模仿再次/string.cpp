#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"string.h"
const size_t npos = -1;
mystring::string::string() 
	:_str(new char[1])
	,_size(0)
	,_capacity(0)
{
	*(_str) = '\0';
}
//
mystring::string::string(const char* arr)
	:_size(strlen(arr))//strlen不会识别\0并记数
{
	_str = new char[_size + 1];
	strcpy(_str,arr);//strcpy可以将'\0'也给拷贝过去
	_capacity = _size;
}
char& mystring::string::operator[](size_t i) {
	return *(_str + i);
}
std::ostream& mystring::operator<<(std::ostream& out, mystring::string& q1) {
	if (q1._size==0) {
		out << " ";
		return out;
	}
	size_t i = 0;
	for (; i < q1._size;i++) {
		out << *(q1._str + i);
	}
	return out;
}
char*& mystring::string::c_str() {
	return _str;
}
//~string
mystring::string::~string() {
		delete[] _str;
}
void mystring::kkk() {

}
mystring::string::string(string& q1) 
:_size(q1._size)
{
	_str = new char[_size + 1];
	_capacity = _size;
	strcpy(_str,q1._str);
}
char mystring::string::operator++() {
	return *(_str + 1);
}

bool mystring::string::full() {
	return _size == _capacity;
}

char* mystring::string::begin() {
	return _str;
}
char* mystring::string::end() {
	size_t i = 0;
	while (*(_str+i)!='\0') {
		++i;
	}
	return _str + i;
}

void mystring::string::Getspace(size_t n) {
	char* pa = _str;
	_str = new char[n];
	strcpy(_str, pa);
	delete[] pa;
	pa =nullptr;
}

void mystring::string::push_back(char ch) {
	if (full()) {
		size_t newcapacity = _capacity == 0 ? 4 : 2 * _capacity;//capacity表示为有效数据空间
		this->Getspace(newcapacity + 1);
		_capacity = newcapacity;
	}
	_size++;
	*(this->end() + 1) = '\0';
	*(this->end()) = ch;
}

void mystring::string::pushchar(size_t len,const char*pa) {
	size_t i = 0;
	for (; i < len;i++) {
		++_size;
		this->push_back(*(pa + i));
	}
}

void mystring::string::append(const char* st) {
	size_t len = strlen(st);
	if (_size + len > _capacity) {
		size_t newcapacity = 2 * _capacity + 1 < _size + len + 1 ? _size + len : 2 * _capacity + 1;//要多开一个空间？？
		Getspace(newcapacity);
	}
	_size += len;
	strcpy(this->end(),st);
}


void mystring::string::operator+=(char a) {
	this->push_back(a);
}

void mystring::string::insert(size_t pos,char ch) {
	assert(pos+1<=_size);
	size_t i = _size + 1;
	char* pa = new char[i];
	strcpy(pa, _str + pos);
	if (full()) {
		size_t newcapacity = _capacity == 0 ? 5 : 2 * _capacity + 1;
		Getspace(newcapacity);
		_capacity = newcapacity - 1;
	}
	++_size;
	*(_str + pos) = ch;
	strcpy(_str+pos+1,pa);
}
void mystring::string::insert(size_t pos,const char* str) {
	assert(pos+1<=_size);
	size_t len = strlen(str);
	if (_size+len>_capacity) {
		size_t newcapacity = 2 * _capacity < _size + len ? _size + len + 1 : 2 * _capacity + 1;
		this->Getspace(newcapacity);
		_capacity = newcapacity;
	}
	char* pa = new char[_size + 1 - pos];
	strcpy(pa, _str + pos);
	strcpy(_str + pos, str);
	strcpy(_str + pos + len, pa);
	_size += len;
}

void mystring::string::erase(size_t pos,size_t len) {
	if (pos + 1 > _size || len == 0) {
		return;
	}
	
	if (pos+1<=_size&&pos+len==_size) {
		_size = pos;
		*(_str + pos) = '\0';
	}
	else {
		size_t small = pos, big = pos + len;
		while (*(_str+big)) {
			*(_str + small) = *(_str + big);
			++small;
			++big;
		}
		*(_str + small) = '\0';
		_size = small;
	}
}
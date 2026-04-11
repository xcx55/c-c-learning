#pragma once
#include<iostream>
#include<assert.h>

namespace mystring {
	static int a = 10;
	//这个量本来不用声明，但是就是要了声明，变量也是有声明定义的！！！
	class string {
	public:
		friend std::ostream& operator<<(std::ostream& out, mystring::string& q1);
		typedef char* iterator;
		char* begin();
		char* end();
		string();
		string(const char* arr);
		string(string& q1);
		char& operator[](size_t i);
		char*& c_str();
		~string();
		char operator++();
		bool full();
		void push_back(char ch);
		void append(const char* st);
		void Getspace(size_t n);
		void operator+=(char a);
		void pushchar(size_t len,const char*pa);
		void insert(size_t pos,char ch);
		void insert(size_t pos,const char* str);
		void erase(size_t pos,size_t len);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		static size_t npos;
	};
	std::ostream& operator<<(std::ostream& out, mystring::string& q1);
	void kkk();
}
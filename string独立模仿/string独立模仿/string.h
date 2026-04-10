#pragma once
#include<iostream>
#include<assert.h>
namespace mystring {
	class string {
	public:
		friend std::ostream& operator<<(std::ostream& out, const mystring::string q1);
		friend std::istream& operator>>(std::istream& in, mystring::string& s);
		string();
		string(mystring::string& a);
		string(const char* str);
		void operator+(char ch);
		char* c_str();
		void space(size_t n);
		void append(const char* str);
		void insert(size_t pos,char ch);
		void insert(size_t pos, const char* str);
	    ~string();
		char& operator[](size_t i);
		void clear();
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	std::ostream& operator<<(std::ostream& out,const mystring::string q1);
	std::istream& operator>>(std::istream& in, mystring::string& s);
	std::istream& Getline(std::istream& in,string& s,char ch);
}
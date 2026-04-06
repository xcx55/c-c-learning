#pragma once
#include<iostream>
#include<assert.h>
namespace sss {
	class string {
	public:
		string();
		string(const char* arr);
		friend std::ostream& operator<<(std::ostream& out, sss::string& a);
		char& operator[](size_t i);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	std::ostream& operator<<(std::ostream& out, sss::string& a);
}
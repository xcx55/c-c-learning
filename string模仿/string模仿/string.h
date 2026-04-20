#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace s {
	class string {
	public:
		friend void hanshu();
		friend std::ostream& operator<<(std::ostream& out, s::string& a);
		string();
		string(const char* arr);
		~string();
		const char* c_str();
		const char& operator[](size_t i);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	std::ostream& operator<<(std::ostream& out, string& a) {
		size_t i = 0;
		while (a[i] != '\0') {
			out << a[i] << " ";
			++i;
		}
		return out;
	}
	void hanshu() {

	}
}


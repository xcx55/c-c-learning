#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"string.h"
#include<iostream>

namespace ss {
	void test_string1() {
		s::string s1;
		std::cout << s1.c_str() << std::endl;
		s::string q2("hello world!");
		cout << q2 << std::endl;
		std::cout << q2[0];
	}
}

int main(){
	ss::test_string1();
	return 0;
}
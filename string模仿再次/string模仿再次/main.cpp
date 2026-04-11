#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"string.h"

int main() {
	mystring::a = 20;
	mystring::string q1;
	std::cout << sizeof(q1) << std::endl;
	q1+='a';
	q1.append("awwaa");
	std::cout << q1 << std::endl;
	q1.erase(1,5);
	std::cout << q1 << std::endl;
	return 0;
}
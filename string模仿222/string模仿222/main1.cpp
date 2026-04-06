#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"string.h"
void test01(){
	sss::string q1("hello world!!!");
	std::cout << q1 << std::endl;
	size_t i = 0;
	while (q1[i]!='\0') {
		q1[i]++;
		++i;
	}
}

int main() {
	test01();
	return 0;
}
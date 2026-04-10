#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"string.h"

int main() {
	mystring::string q("sss");
	q.append("aaa");
	std::cout << q << std::endl;
	q.insert(1,'a');
	std::cout << q << std::endl;
	q.insert(1,"aa");
	std::cout << q << std::endl;
	q[2] = 's';
	std::cout << q << std::endl;
	std::cin >> q;
	std::cout << q << std::endl;
	q.append("qwqwqw!qwqw");
	std::cout << q << std::endl;
	mystring::Getline(std::cin,q,'!');
	std::cout << q << std::endl;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"list.h"

int main() {
	bit::list<int> q1;
	q1.push_back(1);
	q1.push_back(2);
	bit::list<int>::iterator it1 = q1.begin();
	q1.push_back(3);
	q1.push_back(3);
	++it1;
	std::cout << *it1 << std::endl;
	bit::print(q1);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"list.h"
struct pos {
	int a1;
	int a2;
	pos(int a = 0, int b = 0)
		:a1(a)
		,a2(b)
	{}
};
int main() {
	bit::list<pos> a3;
	bit::list<pos>::iterator it1 = a3.begin();
	a3.push_back({1,2});
	std::cout << (*it1).a1;
	it1++;
	std::cout << (*it1).a1;
	return 0;
}
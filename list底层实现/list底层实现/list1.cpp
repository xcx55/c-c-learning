#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"list.h"

int main() {
	bit::list<int> q1;
	q1.push_back(1);
	bit::list<int>::iterator q2=q1.end(); // 修正：使用正确的迭代器类型名，并指定int类型
	std::cout << *q2 << std::endl;
	return 0;
}
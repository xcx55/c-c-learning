#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"stack_queue.h"
template<class container1>
void print(container1& x) {
	for (auto& s: x) {
		std::cout << s << " ";
	}
}


int main() {
	bit::priority_queue<int> pq;
	pq.push(1);
	pq.push(100);
	pq.push(222);
	pq.push(222);
	pq.pop();
	print(pq);
	pq.pop();
	std::cout << std::endl;//怎么找的：先变为语法糖-》函数   std::cout.operator<<(std::endl);去std的cout域去找！
	print(pq);
	return 0;
}


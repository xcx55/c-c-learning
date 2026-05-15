#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//class queue_priority;
#include "queue-priority.h"

int main() {
	std::vector<int> q2{ 1,3,776,37283,3738 };
	bit::priority_queue<int,bit::greator<int>> q1(q2.begin(), q2.end());
	/*std::cout << bit::priority_queue<int>::a << std::endl;*/
	q1.push(222);
	bit::print(q1);
	return 0;
}
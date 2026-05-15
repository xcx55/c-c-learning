#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"±êqueue_priority.h"

int main() {
	std::vector<int> q2{ 1,2,3,0,122,265782 };
	xcx::priority_queue<int,xcx::greator<int>> q1(q2.begin(), q2.end());
	xcx::priority_queue<int> q4;
	q1.push(1);
	q1.push(3);
	q1.push(182);
	/*q1.push(182);*/
	/*q1.pop();*/
	xcx::print(q1);
	return 0;
}
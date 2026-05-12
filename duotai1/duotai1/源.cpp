#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"vector.h"


int main() {
	bit::vector < bit::vector<int >> q1;
	bit::vector < bit::vector<int >> q2(q1);
	q2[0].push(1); q2[0].push(1); q2[0].push(1); q2[0].push(1);
	q2[0].push(1);
	bit::print(q2[0]);
	//bit::vector<int> q1;
	//q1.push(2);
	//bit::vector<int> q2(q1);
	//bit::vector<int>::iterator it1 = q1.begin();
	//cout << *it1 << endl;//要先转换语法糖
	///*cout << q1.size() << endl;
	//cout << q2.size() << endl;
	//cout << q1.capacity() << endl;
	//cout << q2.capacity() << endl;*/
	///*bit::print(q2);*/
	return 0;
}
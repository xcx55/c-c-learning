#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"list.h"
using namespace std;
struct dd {
	int _a;
	dd(int s = 0) {
		_a = s;
	}
};
int main() {
	bit::list<int> q1;
	q1.push_back(1);
	q1.push_back(1);
	q1.push_back(1);
	bit::list<int>::iterator it1 = q1.begin();
	cout << *it1 << endl;
	q1.insert(it1, 2);
	bit::print(q1);
	return 0;
}
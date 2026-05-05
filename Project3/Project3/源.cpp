#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>
void swap(int& a,int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void duiup( std::vector<int>& q2) {
	int child = q2.size() - 1;
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (q2[parent]<q2[child]) {
			swap(q2[parent],q2[child]);
			child = parent;
			parent= (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
int main() {
	std::vector<int> q1{21, 32, 982, 22, 3, 0, 43};
	std::vector<int> q2;
	while (!q1.empty()) {
		q2.push_back(q1.back());
		q1.pop_back();
		duiup(q2);
	}//983,43,32,0,22,3,21
	std::vector<int>::iterator it1 = q2.begin();
	std::vector<int>::iterator it2 = q2.end();

	while (it1!=it2) {
		std::cout << q2.back() << " ";
		q2.pop_back();
	}
	return 0;
}
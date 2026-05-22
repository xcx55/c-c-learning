#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"BStree.h"

int main() {
	bit::BStree<int> q1;
	q1.insert(0);
	q1.insert(2);
	q1.insert(2);
	q1.insert(33);
	q1.insert(-1);
	q1.insert(20);
	q1.insert(212);
	q1.insert(12);
	q1.insert(9);
	if (q1.find(2)) {
		q1.Erase(2);
		q1.InOrder();
	}
	return 0;
}
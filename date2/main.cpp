#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"date.h"

int main() {
	date q1(2026,3,16);
	date q3=q1 + 15;
	q3.print();
	return 0;
}
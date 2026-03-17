#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"date.h"

int main(){
	date q1(2026,3,17);
	date q2 = q1 - 3232;
	q2. print();
	return 0;
}
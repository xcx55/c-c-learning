#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"vector.h"

int main() {
	xcx::vector<xcx::vector<int>> a1(2);
	a1[0].push_back(2);
	a1[0].push_back(2);
	a1[0].push_back(2);
	a1[0].push_back(2);
	
	xcx::print(a1[0]);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"vector.h"
#include<string>
int main() {
	bit::vector<string> a1(20);
	a1[0].push_back("111");
	bit::print(a1[0]);
	//bit::vector<string> a1(4);
	//a1.push_back("aaa");
	//bit::print(a1[0]);
	///*size_t h(100);*/
	//bit::vector <bit::vector<int>> a2{ 3 };//这里的复合嵌套
	//bit::vector<int> a3;
	//a2.push_back(a3);
	//bit::print(a2);
	///*bit::vector<int> a1;
	//bit::vector<int> a3(5,1);
	//bit::print(a3);*/
	///*a1 = 2;
	//a1.push_back(1);
	//a1.push_back(2);
	//a1.push_back(4);
	//a1.resize(9);
	//a1.insert(a1.begin(), 14);
	//for (auto& e:a1) {
	//	cout << e << " ";
	//}
	//cout << endl;
	//bit::vector<int>::iterator it1 = a1.begin();
	//for (auto& e:a1) {
	//	if ((*it1) % 2 == 0) {
	//		it1 = a1.erase(it1);
	//	}
		/*else
			++it1;
	}
	bit::print(a1);*/
	
	return 0;
}
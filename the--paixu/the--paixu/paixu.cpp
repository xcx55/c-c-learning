#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
	int a = 0;
	a = (int)(1.33*11);
	cout << a;
	return 0;
}






//class A {
//public:
//	A(int x=5) {
//		cout << "A构造" << endl;
//		data = x;
//	}
//	~A() {
//		cout << "A析构" << endl;
//	}//delete就是代言人？？free的 析构函数删除内部资源
//private:
//	int data;
//};
//
//
//class stack {
//public:
//	stack(int n = 4)
//		:_arr(new A[n])
//		, top(0)
//		, capacity(4)
//	{
//		cout << "构造" << endl;
//	}
//	~stack() {
//		delete[] _arr;//只需要提供首元素地址，它就会找到其元素个数
//		cout << "析构" << endl;
//	}
//private:
//	A* _arr;
//	int top;
//	int capacity;
//};
//
//int main() {
//	stack* pa = new stack{ 10 };//调用构造函数
//	delete (pa);
//	return 0;
//}






















//class date {
//public:
//	~date() {
//		cout << "析构" << endl;
//	}
//
//	date(int year = 1/*, int month = 1, int day = 1*/)
//		:_year(year)
//		/*, _month(month)
//		, _day(day)*/
//	{
//		cout << "构造函数"<<endl;
//	}
//private:
//	int _year;
//	/*int _month;
//	int _day;*/
//};
//
//int main() {
//	date* pa = new date[10];
//	cout << pa << endl;
//	delete pa;
//	return 0;
//}
//
////#define sz 20
////int* Get() {
////	int* arr = new int[10] {1, 3, 2, 7, 9, 6, 5, 4, 3, 6};
////	return arr;
////}
////void swap(int& a,int& b) {
////	int tmp = a;
////	a = b;
////	b = tmp;
////}
////希尔排序
////int main() {
////	int gap = 3;
////	int* arr = Get();
////	int i = 0;
////	while (gap>=1) {
////		while (i+gap<9) {
////			gap /= 3;
////			int count = i;
////			while (count>0) {
////				if (arr[count]>arr[count+gap]) {
////					swap(arr[count],arr[count+gap]);
////					count -= gap;
////				}
////				else {
////					count += gap;
////				}
////				if (count + gap >= 9) {
////						break;
////				}
////			}
////			i++;
////		}
////	}
////	return 0;
////}
////int main() {
////	float arr[sz] = { 0 };
////	for (int i = 0; i < sz;i++) {
////		cin >> arr[i];
////	}
////	int sum = 0;
////	for (int j = 0; j < sz;j++) {
////		sum += arr[j];
////	}
////	float a = (float)sum / sz;
////	cout << "\n";
////	cout << a;
////	return 0;
////}
//

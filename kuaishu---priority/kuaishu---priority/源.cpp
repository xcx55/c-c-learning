#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
//快速排序---三路划分
void swap(int& a,int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
//void quick_sortthreepath(int* arr,int left,int right) {
//	if (left>=right) {
//		return;
//	}
//	int key = arr[left];
//	int i = left, j = right, v = left + 1;
//	while (i<j) {
//		if (arr[v]<key) {
//			swap(arr[i],arr[v]);
//			++i;
//			++v;
//		}
//		else if (arr[v]>key) {
//			swap(arr[v],arr[j]);
//			--j;
//		}
//		else {
//			++v;
//		}
//	}
//	quick_sortthreepath(arr, left, i - 1);
//	quick_sortthreepath(arr, v, right);
//}
//int main() {
//	int arr[10]
//	quick_sortthreepath(arr,0,9);
//	for (int i = 0; i < 10;i++) {
//		std::cout << arr[i] << " ";
//	}
//	return 0;
//}

//堆排序
void downadjust(int* arr, int parent, int n) {
	int child = 2 * parent + 1;
	while (child<n) {
		if (child + 1 < n && arr[child] < arr[child + 1]) {
			++child;
		}
		if (arr[child]<=arr[parent] ) {
			break;
		}
		else {
			swap(arr[child], arr[parent]);
		}
		parent=child;
		child = 2 * parent + 1;
	}
}
void queuesort(int* arr,int n) {
	int j = (n - 1) / 2;
	for (int t = j; t >= 0;t--) {
		downadjust(arr, t, n);
	}
	int size = n - 1;
	while (size--) {
		::swap(arr[size + 1], arr[0]);
		downadjust(arr, 0, size + 1);
	}
}
int main() {
	int arr[10]{ 32,86,47,38937,3378,29,8,0,87,378 };
	queuesort(arr,10);
		for (int i = 0; i < 10;i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}
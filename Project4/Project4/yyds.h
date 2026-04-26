#pragma once
#include<iostream>
using namespace std;

namespace bit {
	template <class T>
	class stack {
	public:
		void print();
		friend ostream& operator<<(ostream& out, bit::stack<T>q1);
		stack(int n = 4)//赋值，初始化列表提供更高权限
			//此时已经尝试构建了一次，赋随机值,且出了初始化列表才有this指针
		{
			this->_arr = new T[n];
			this->_top = 0;
			this->_capacity = n;
			cout << "gouzao" << endl;
		}
		~stack() {//析构函数仅仅清理内部资源
			delete[] _arr;
			cout << "xigou" << endl;
		}
		void push(T n) {
			if (_capacity == _top) {
				int tmp = _capacity == 0 ? 4 : 2 * _capacity;
				T* pa = new T[tmp]; print();
				memcpy(pa, this->_arr, sizeof(T) * (this->_top));
				_arr = pa;
				_capacity = tmp;
			}
			_arr[_top++] = n;
		}
		
	private:
		T* _arr;
		int _top;
		int _capacity;
	};
}
	


template <class T>
void bit::stack<T>::print() {
	cout << " " << endl;
}

class date {
public:
	date(int year,int month,int day)
	//构造this指针！
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print(){}
private:
	int _year;
	int _month;
	int _day;
};
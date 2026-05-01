#pragma once
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;
namespace xcx {
	template <class T>
	class vector {
	public:
		//operator[]
		T& operator[](size_t i) {
			return *(_start + i);
		}
		typedef T* iterator;

		//begin()
		iterator begin() {
			return _start;
		}

		//end()
		iterator end() {
			return _finish;
		}

		//reserve
		void reserve(size_t n) {
			iterator tmp = new T[n];
			size_t old_size = size();
			for (size_t i = 0; i < size(); i++) {
				tmp[i] = _start[i];//递归调用
			}
			_start = tmp;
			_finish = _start + old_size;
			_end = _start + n;
		}
		//size()
		size_t size() {
			return _finish - _start;
		}
		//push_back
		void push_back(T x) {//拷贝出来的也是
			if (_finish==_end) {
				reserve(_finish == nullptr ? 4 : 2 * capacity1());
			}
			*(_finish++) = x;//又会调用，这里赋值又是一次operator=，也是深拷贝
		}
		//~vector
		~vector() {
			delete[] _start;
		}
		//构造
		vector(size_t n = 4)
		{
			iterator pa = new T[n];
			_start = pa;
			_finish = _start;
			_end = _start + n;
		}
		vector(iterator it1,iterator it2) {
			assert(it1 > it2);//左闭右开
			size_t n = it2 - it1;
			iterator tmp = new T[n];
			for (size_t i = 0; i < n;i++) {//类赋值，拷贝之类的，都要进行操作
				tmp[i] = _start[i];
			}
		}
		//capacity
		size_t capacity1() {
			return _end - _start;
		}
		bool capacity2() {
			return _finish == _end;
		}
		vector(vector<T>& x) {
			T* tmp = new T[x.capacity1()];
			size_t old_size = x.size();
			for (size_t i = 0; i < x.capacity1(); ++i) {
				tmp[i] = x._start[i];//就是这么用for循环，无限调用operator=函数
			}
			_start = tmp;
			_finish = _start + old_size;
			_end = _start + this->capacity1();
		}

		void swap(vector<T>& x) {
			std::swap(_start,x._start);
			std::swap(_finish,x._finish);
			std::swap(_end,x._end);
		}
		void operator=(vector<T> x) {//是a=b,还是A a=b;都是将拷贝一个参数对象，a=b基础上有A a=b;
			swap(x);
		}
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end = nullptr;
	};
	template <class c>
	void print(c x) {
		for (auto& e:x) {
			std::cout << e << " ";
		}
	}
}
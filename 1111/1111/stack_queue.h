#pragma once
#include<iostream>
#include<vector>

namespace bit {
	template<class T, class container = std::vector<T>>
	class priority_queue {
	public://只是权限检查，只不过我们要写它的时间很靠前，所以以为权重很重，将这个域的信息打散为符号表
		priority_queue() {

		}
		typename container::iterator begin() {
			return _con.begin();
		}
		
		typename container::iterator end() {
			return _con.end();
		}
		


		void swap(T& a, T& b) {
			T vv = a;
			a = b;
			b = vv;
		}
		
		void pop() {
			this->swap(_con[0],_con[_con.size()-1]);
			_con.pop_back();
			this->adjustdown(0);
		}

		void push(const T& x) {
			_con.push_back(x);
			this->adjustup();
		}
	private:
		void adjustdown(size_t parent) {
			size_t child = 2 * parent + 1;
			while (child<_con.size()) {
				if (child<_con.size()-1&&_con[child+1]>_con[child]) {
					++child;
				}
				if (_con[child]<_con[parent]) {
					break;
				}
				else {
					this->swap(_con[child],_con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
			}
		}
		void adjustup() {
			size_t child = _con.size() - 1;
			size_t parent = (child - 1) / 2;
			while (child > 0) {
				if (_con[parent] < _con[child]) {
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}

		}
		container _con;//只是量，直接就是找名字，private权限，好了，直接替换为基指针+偏移量（查表）
	};
}
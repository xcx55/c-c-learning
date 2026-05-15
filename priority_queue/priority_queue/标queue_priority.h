#pragma once
#include<iostream>
#include<vector>
namespace xcx {
	template <class T>
	struct Less {
		bool operator()(T x,T y)const {
			return x < y;
		}
	};
	template <class T>
	struct greator {
		bool operator()(T x, T y)const {
			return x > y;
		}
	};

	template<class T, class compare=Less<T>, class container = std::vector<T>>
	class priority_queue {
	public:
		priority_queue() = default;
		template <class A>
		priority_queue(A begin,A end) {
			while (begin != end) {
				this->push(*begin);
				++begin;
			}
		}
		void push(T x) {
			_con.push_back(x);
			adjustup();
		}
		typename container::iterator begin() {
			return _con.begin();
		}
		typename container::iterator end() {
			return _con.end();
		}
		T& top()const {
			return _con.top();
		}
		void pop() {//const的作用
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjustdown(0);
		}
	private:
		void swap(T& x, T& y) {
			T tmp = x;
			x = y;
			y = tmp;
		}
		void adjustdown(size_t parent) {
			compare com;
			size_t child = 2 * parent + 1;
			while (child<_con.size()) {
				if (child + 1 < _con.size() &&!com(_con[child + 1] , _con[child]))//这里不要！
				/*if (child + 1 < _con.size() && _con[child + 1]> _con[child])*/
				{ ++child; }
				if (com(_con[child] , _con[parent]))
				/*if(_con[child] > _con[parent])*/
				{ swap(_con[child] , _con[parent]); }
				else { break; }
				parent = child;
				child = 2 * parent + 1;
			}
		}
		void adjustup() {
			compare com;
			int child = _con.size() - 1;
			int parent = (child - 1) / 2;
			while (child > 0) {
				if (com(_con[parent], _con[child])) {
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}
		}
		container _con;
	};
	template<class Container>
	void print(Container& xx) {
		for (auto& e:xx) {
			std::cout << e << " ";
		}
	}
}

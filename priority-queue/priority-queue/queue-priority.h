#pragma once
#include<vector>
#include<queue>
#include<iostream>
#include<deque>
namespace bit {
	template<class T>
	struct Less {
		bool operator()(T x,T y)const {
			return x < y;
		}
	};
	template<class T>
	struct greator {
		bool operator()(T x, T y)const {
			return x > y;
		}
	};
	template<class T, class compare=Less<T>, class container = std::vector<T>>
	class priority_queue {
	public:
		priority_queue() = default;
		template<class x>
		priority_queue(x first,x end) 
			/*:_con(first,end)*/
		{
			while(first!=end){
				_con.push_back(*first);
				++first;
			}
			for (int t = (_con.size() - 1 - 1) / 2; t >= 0; t--) {
				adjustdown(_con,t);
			}
		}
		typename container::iterator begin() {return _con.begin();}
		typename container::iterator end() {return _con.end();}
		void swap(T& a, T& b) {
			T vv = a;
			a = b;
			b = vv;
		}
		
		tempalte<>
			void ff<char>() {

		}

		void push(const T& x) {
			_con.push_back(x);
			// 传入当前元素数量（size），而不是 capacity
			adjustup(_con, _con.size());
		}
		void pop() {
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjustdown(_con, 0);
		}
		const T& top()const {
			return _con[0];
		}
		bool empty()const {
			return _con.empty();
		}
		size_t size()const {
			return _con.size();
		}
		/*static int a;*/
		//仿函数
	private:
		void adjustdown(container& x, size_t parent) {//向下调整和向上调整其实差不多
			size_t child = 2 * parent + 1;
			compare com;
			while (child<x.size()) {
				if (child + 1 < x.size() && x[child] < x[child + 1]) {
					++child;
				}
				if (com(x[child],x[parent]))
				/*if(x[child]<x[parent])*/ {
					break;
				}
				else {
					swap(x[child], x[parent]);
				}
				parent = child;
				child = 2 * parent + 1;
			}
		}
		void adjustup(container& con, size_t n) {//向上调整法
			size_t child = n - 1;
			if (child == 0) {
				return;
			}
			size_t parent = (child - 1) / 2;
			while (child > 0) {
				compare com;
				/*if (con[parent] < con[child])*/ 
				if(com(con[parent] , con[child])){
					swap(con[parent], con[child]);
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
	template<class container>
	void print(container& x) {
		for (auto& e:x) {
			std::cout << e << " ";
		}
	}
}

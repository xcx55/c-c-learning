#pragma once
//#include<vector>
#include<iostream>
#include<assert.h>
//#include<vector>
using namespace std;
namespace bit {
	template<class T>
	class vector {
	public:
		
		typedef T* iterator;

		iterator insert(iterator& pos, const T& x) {
			size_t xx = pos - _start;
			assert(pos < end() && _finish);
			if (_finish == _endofshortage) {
				size_t vv = pos - _start;
				reserve(_endofshortage == nullptr ? 4 : 2 * capacity());
				pos = _start + vv;
			}
			iterator a = _finish;
			while (a - 1 >= pos) {
				(*a) = (*(a - 1));
				--a;
			}
			*a = x;
			++_finish;//易错
			return _start + xx;
		}


		void pop_back() {
			assert(_finish>_start);
			_finish--;
		}

		iterator& begin() {
			return _start;
		}
		iterator& end() {
			return _finish;
		}

		size_t size() {
			return _finish - _start;
		}
		T& operator[](size_t i) {
			assert(i+_start<_finish);
			return *(_start + i);
		}

		iterator erase(iterator x) {
			iterator z = x;
			assert(x >= _start && x < end());
			if (_start + 1 == _finish) {
				_start = _finish = _endofshortage = nullptr;
				return nullptr;
			}
			while (x<end()) {
				*x = *(x + 1);
				++x;
			}
			--_finish;
			return z;
		}
		/*vector(iterator it1,iterator it2) {
			iterator it3 = it1;
			size_t capacity1 = it3 - it1;
			_start = new T[capacity1];
			memcpy(_start,it1,capacity1*sizeof(T));
			_finish = _start + capacity1;
			_endofshortage = _finish;
		}*/
		



		void reserve(size_t n) {
			if (!_start) {
				_start = new T[n];
				_finish = _start;
				_endofshortage = _start + n;
			}
			else {
				size_t old_size = size();
				iterator q1 = new T[n];
				for (size_t i = 0; i < size(); ++i) {
					q1[i] = _start[i];
				}
				delete[] _start;
				_start = q1;
				_finish = _start + old_size;
				_endofshortage = _start + n;
			}
		}
		
		/*T* find(T* start,T* end,T x) {
			assert(start >= _start && end <= _finish);
			while (start <= end) {
				if (*(start) == x) {
					return start;
				}
				++start;
			}
			return end();
		}*/

		void resize(size_t n, T x = T()) {
			T* pa = new T[n];
			if (_endofshortage==nullptr) {
				_start = pa;
				_finish = _start;
				_endofshortage = _start + n;
				pa = nullptr;
				while (_finish!=_endofshortage) {
					push_back(x);
				}
				return;
			}
			if (end()-begin()>=n) {
				/*memcpy(pa, _start, n * sizeof(T));*/
				for (size_t i = 0; i < n;++i) {
					pa[i] = _start[i];
				}
				T* sss = _start;
				_start = pa;
				_finish = _start + n;
				_endofshortage = _finish;
				delete[] sss;
				sss = nullptr;
				return;
			}
			else {
				T* fff = _start;
				size_t ss = end() - begin();
				/*memcpy(pa, _start, ss * sizeof(T));*/
				for (size_t i = 0; i < ss; ++i) {
					pa[i] = _start[i];
				}
				_start = pa;
				_finish = _start + ss;
				_endofshortage = _start + n;
				delete[] fff;
				pa = nullptr;
				size_t i = n - ss;
				while (i--) {
					*(_finish) = x;
					++_finish;
				}
			}
		}

		template <class cc>
		vector(cc it1, cc it2) {
			while (it1 != it2) {
				push_back(*it1);
				++it1;
			}
		}
		/*vector(T x = T())//这个不能要，没有一个值的初始化
			:_start(nullptr)
			, _finish(nullptr)
			, _endofshortage(nullptr)
		{
			push_back(x);
			cout << "vector()" << endl;
		}*/
		//构造
		vector(int x = 1, T c = T()) {
			cout << "vector()1" << endl;
			resize(x, c);
		}

		size_t capacity()
		{
			return _endofshortage - _start;
		}

		bool capacity1() {//md这里要是bool之前是返回size_t!!!!
			return _endofshortage == _finish;
		}

		void push_back(const T x) {
			if (capacity1()) {
				reserve(_endofshortage == nullptr ? 4 : 2 * capacity());
			}
			*(_finish) = x;
			++_finish;
		}

		/*T& operator[](size_t i) {
			if (capacity()==0) {
				return *(_start + i);
			}
		}*/

		~vector() {
			if (_endofshortage) {
				delete[] _start;
			}
			_start = _finish = _endofshortage = nullptr;
		}
		void swap(vector<T>& a) {
			std::swap(_start,a._start);
			std::swap(_finish, a._finish);
			std::swap(_endofshortage, a._endofshortage);
		}
		
		vector(bit::vector<T>& a)
		{
			size_t i = a._finish - a._start;
			size_t j = a._endofshortage - a._start;
			_start = new T[j];
			for (int i = 0; i < a.capacity(); ++i) {
				_start[i] = a._start[i];
			}
			_finish = _start + i;
			_endofshortage = _start + j;
		}

		void operator=(bit::vector<T> x) {
			this->swap(x);
		}
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofshortage = nullptr;
	};
	template<class container>
	void print(const container& a) {//传入容器
		for (auto& e:a) {
			cout << e << " ";
		}
	}
}
#pragma once
#include<iostream>
using namespace std;

namespace bit {
	template<class T>
	class vector {
	public:
		vector(size_t n = 4) {//有定义有空间
			this->_begin = new T[n];
			this->_finish = _begin;
			this->_endofshortage = _begin + 4;
		}
		void Getnewspace() {
			printff();
			size_t newcapacity = 2 * this->size() + 1;
			size_t old_size = size();
			T* ptr = new T[newcapacity];
			for (size_t i = 0; i < old_size;i++) {
				ptr[i] = _begin[i];
			}
			_begin = ptr;
			_finish = _begin + old_size;
			_endofshortage = ptr + newcapacity;
		}

		void swap(T*& x,T*& y) {
			T* tmp = x;
			x = y;
			y = tmp;
		}

		void operator=(vector x) {
			swap(_begin,x._begin);
			swap(_finish, x._finish);
			swap(_endofshortage, x._endofshortage);
		}


		void push(const T& x) {
			if (!empty()) {
				Getnewspace();
			}
			*(_finish++) = x;
		}
		
		T& operator[](size_t i) {
			return *(_begin + i);
		}

		bool empty() {
			return _endofshortage != _finish;
		}
		size_t size() {
			return _finish - _begin;
		}

		template<class ptr,class self>
			class iterator1 {
			public:
			iterator1(T* x) {
				_ptr = x;
			}
			self operator*() {
				return *_ptr;
			}



			ptr _ptr;
		};
			typedef iterator1<T*, T&> iterator;
			typedef iterator1<const T*, const T&> const_iterator;

		T* end() {
			return _finish;
		}
		T* begin() {
			return _begin;
		}
		size_t capacity() {
			return _endofshortage - _begin;
		}

		template<class container>
		vector(container& x) {
			size_t size = x.size();
			size_t capacity = x.capacity();
			_begin = new T[capacity];
			_finish = _begin;
			_endofshortage = _begin + x.capacity();
			for (int i = 0; i < size;i++) {
				_begin[i] = x[i];
			}
			_finish = _begin + x.size();
		}
	private:
		T* _begin;//无空间，有趣，地位相同
		T* _finish;//前面加上短横线的原因，原来是这样的！！！！查找规则！！
		T* _endofshortage;
	};

	template<class Container>
	void print(Container& x) {
		for (auto& c:x) {
			cout << c << " ";
		}
	}
	
}
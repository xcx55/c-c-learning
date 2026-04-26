#pragma once
#include<iostream>

namespace bit {
	template<class T>
	struct listnode {
		T data;
		listnode* _next;
		listnode* _prev;
		listnode(T x=T()){
			data = x;
			_next = nullptr;
			_prev = nullptr;
		}
	};
	template <class T>//记录T为什么类型
	class list {
	public:
		typedef bit::listnode<T> node;//符号表记录
		template<class T, class ref, class ptr>//知道符号表知识后，就以模板之类的正常写代码
		class _list__iterator {
			typedef _list__iterator<T, ref, ptr> iterator;
		public:
			_list__iterator(node* x) {
				_node = x;
			}
			
			T& operator*() {
				return _node->data;
			}
			iterator operator++() {
				_node = _node->_next;
				return *this;
			}
			iterator operator++(int) {
				node* pa = _node;
				_node = _node->_next;
				return pa;
			}
			iterator operator--() {
				_node = _node->_prev;
				return *this;
			}
			iterator operator--(int) {
				node* pa = _node;
				_node = _node->_prev;
				return pa;
			}

			bool operator!=(const iterator& q1) {
				return _node != q1._node;
			}
			bool operator==(const iterator& q1) {
				return _node == q1._node;
			}
			node* operator->() {
				return _node;
			}
		private:
			node* _node;
		};
	
		list(T x=T()) 
		{
			_head = new node{ x };
			_head->_next = _head;
			_head->_prev = _head;
		}
		~list() {
			node* pa = _head->_next;
			node* pb = pa->_next;
			while (pa != _head) {
				delete pa;
				pa = pb;
				pb = pb->_next;
			}
			delete _head;
			pa = pb = _head = nullptr;
		}

		void push_back(T x=T()) {
			node* pa = new node{ x };
			node* tail = _head->_prev;
			pa->_next = _head;
			pa->_prev = tail;
			tail->_next = pa;
			_head->_prev = pa;
		}
		typedef _list__iterator<T, T&, T*> iterator;
		typedef _list__iterator<T, const T&, const T*> const_iterator;
		iterator begin() {
			return _head->_next;
		}
		const_iterator begin()const {
			return _head->_next;
		}
		iterator end() {
			return _head;
		}
		const_iterator end()const {
			return _head;
		}
		iterator insert(iterator it1, T x = T()) {
			node* pa = new node{ x };
			node* prev = it1->_prev;
			node* next = it1->_next->_prev;
			prev->_next = pa;
			pa->_next = next;
			next->_prev = pa;
			pa->_prev = prev;
			return pa;
		}


	private:
		node* _head;
	};
	template<class container>
	void print(container& q) {
		for (auto& e:q) {
			std::cout << e << " ";
		}
	}
}

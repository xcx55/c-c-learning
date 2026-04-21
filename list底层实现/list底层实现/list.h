#pragma once
#include<iostream>
#include<assert.h>
namespace bit {
	template <class T>
	struct list_node {
		T _data;//和class public等价
		list_node* _next;
		list_node* _prev;
		list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{
		}
	};
	

	template <class T>
	class list {
	public:
		template <class T>
		struct __list_iterator {
			typedef list_node<T> node;
			node* _node;

			__list_iterator(node* pa)
			{
				_node = pa;
			}
			
			T& operator*() {
				return _node->_data;
			}

			T& operator++() {
				_node = _node->_next;
				return *this;
			}
			bool operator!=(const node& x) {
				return _node != x._node;
			}
		};


		typedef __list_iterator<T> iterator;
		typedef list_node<T> node;
		list()//构造函数
		{
			node* pa = new node;
			_head = pa;
			_head->_next = _head;
			_head->_prev = _head;
		}
		void push_back(const T& x) {
			node* pa = new node;
			pa->_data = x;
			node* tail = _head->_prev;
			_head->_prev = pa;
			pa->_next = _head;
			pa->_prev = tail;
		}

		iterator begin() {
			return _head;
		}
		iterator end() {
			return _head->_prev;
		}

	private:
		node* _head;
	};
}

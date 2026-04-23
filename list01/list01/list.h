#pragma once
#include<iostream>

namespace bit {
	template<class T>
	struct listnode {
		T _data;
		listnode<T>* _next;
		listnode<T>* _prev;
		listnode(T x=T()) 
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
	};
	template<class T>
	class list {
	public:
		typedef listnode<T> node;

		//µü´úÆ÷
		template<class T, class ref>
		struct _list__iterator {

			typedef _list__iterator<T, ref> self;
			node* _node;

			_list__iterator(node* x) {
				_node = x;
			}

			self operator++(int) {
				iterator q1 = *this;
				_node = _node->_next;
				return q1;
			}

			node* operator->() {
				return &_head->_data;
			}
			

			ref operator*() {
				return _node->_data;
			}
			self operator++() {
				return (_node->_next);
			}
			self operator--() {
				return _node->_prev;
			}

			bool operator!=(const _list__iterator& q1) {
				return _node != q1._node;
			}
			bool operator==(const _list__iterator& q1) {
				return _node == q1._node;
			}
		};
		typedef _list__iterator<T,T&> iterator;
		typedef _list__iterator<T, const T&> const_iterator;
		

		list() 
			:_head(new node)
		{
			_head->_next = _head;
			_head->_prev = _head;
		}
		~list() {
			node* head = _head->_next;
			do {
				node* pa = head;
				delete head;
				head = pa;
				pa = pa->_next;
			} while (head!=_head->_next);
			delete _head;
		}

		void push_back(const T x) {
			node* newnode = new node;
			newnode->_data = x;
			node* aa = _head->_prev;
			_head->_next = newnode;
			newnode->_next = _head->_next;
			newnode->_prev = aa;
		}

		iterator begin() {
			return _head->_next;
		}
		iterator end() {
			return _head->_prev;
		}
	private:
		node* _head;
	};
}

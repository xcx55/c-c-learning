#pragma once
#include<iostream>

namespace bit {
	template<class T>
	struct listnode {
		T _data;
		listnode* _next;
		listnode* _prev;
		listnode(T x=T()) 
			:_data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}
		listnode(const listnode& q1) {
			_data = q1._data;
			_next = _prev = nullptr;
		}
		
	};
	
	template<class T>
	class list {
	public:
		//c++98竟然只能这样！！！using//list和listnode在同一个域！！！
		typedef listnode<T> node;
		template<class T, class ref, class ptr> 
		struct _list__iterator {
			node* _node;
			typedef _list__iterator<T, ref, ptr> self;
			_list__iterator(node* paa) {
				_node = paa;
			}
			_list__iterator(const _list__iterator& q1) {
				_node = q1._node;
			}
			ref operator*() {
				return _node->_data;////
			}
			ptr operator->() {
				return &(_node->_data);
			}

			self operator++() {
				_node = _node->_next;
				return _node;
			}

			self operator++(int) {
				node* pa = _node;
				_node = _node->_next;
				return pa;
			}
			self operator--() {
				_node = _node->_prev;
				return _node;
			}

			self operator--(int) {
				node* pa = _node;
				_node = _node->_prev;
				return pa;
			}

			bool operator!=(const _list__iterator& other) const {
				return _node != other._node;
			}

			bool operator==(const _list__iterator& other) const {
				return _node == other._node;
			}
			//typedef _list__iterator<T, T&, T*> iterator;//算是传入了参数，虽然这个参数是模板，而且这个参数有相互关系，传入了参数
			//typedef _list__iterator<T, const T&, const T*> const_iterator;//算是传入了参数，传入了参数
		};
		typedef _list__iterator<T, T&, T*> iterator;//算是传入了参数，虽然这个参数是模板，而且这个参数有相互关系，传入了参数
		typedef _list__iterator<T, const T&, const T*> const_iterator;//算是传入了参数，传入了参数
		//实例化了，但是为一对多的情况，T具有多态性！！！ 还是生成了模板
		////是合法的，编译器就不会管了，传入参数后，就是T实例化了，两个都生效，用哪个，

		iterator begin() {
			return _head->_next;
		}

		iterator end() {
			return _head;
		}

		const_iterator begin()const {
			return _head->_next;
		}

		const_iterator end()const {
			return _head;
		}

		list() {
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		void push_back(T x) {
			node* pa = new node;
			pa->_data = x;
			node* tail = _head->_prev;
			tail->_next = pa;
			pa->_next = _head;
			pa->_prev = tail;
			_head->_prev = pa;
		}

		~list() {
			node* pa = _head->_next;
			do {
				node* pss = pa->_next;
				delete pa;
				pa = pss;
				pss = pss->_next;
			} while (pa!=_head);
			delete _head;
			_head = nullptr;
		}

		/*void erase(iterator& it1) {
			node*
		}*/

	private:
		node* _head;
	};

	template <class container>
	void print(container& q1) {
		for (auto& e:q1) {
			std::cout << e << " ";
		}
	}
}


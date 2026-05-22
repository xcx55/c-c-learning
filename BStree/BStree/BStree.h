#pragma once
#include<iostream>

namespace bit {
	template<class K>
	struct BSnode {
		K _data;
		BSnode* _left;
		BSnode* _right;
		BSnode(const K& x = K()) {
			this->_data = x;//又不是virtual函数，就是静态绑定！
			_left = nullptr;//偏移量
			_right = nullptr;
		}
	};


	template<class K>
	class BStree {
	public:
		typedef BSnode<K> node;
		BStree(const K& x=K()) {
			this->_root = new node(x);
		}
		//INSERT
		bool insert(const K& x) {
			node* cur = _root;
			node* parent = cur;
			while (cur) {
				if (cur->_data < x) {
					parent = cur;
					cur = cur->_right;
				}
				else if(cur->_data > x) {
					parent = cur;
					cur = cur->_left;
				}
				else {
					return false;
				}
			}
			if (parent->_data < x) {
				parent->_right = new node(x);
			}
			else {
				parent->_left = new node(x);
			}
			return true;
		}
		void InOrder() {
			print(_root);
		}
		bool find(const K& x) {
			node* pa = _root;
			while (pa) {
				if (pa->_data==x) {
					return true;
				}
				if (pa->_data < x) {
					pa = pa->_right;
				}
				else {
					pa = pa->_left;
				}
			}
			return false;
		}
		bool Erase(const K& x) {
			node* cur = _root;
			node* parent = cur;
			while (cur) {
				if (cur->_data < x) {
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_data > x) {
					parent = cur;
					cur = cur->_left;
				}
				else {
					if (cur->_left == nullptr && cur->_right == nullptr) {
						if (cur->_data<parent->_data) {
							parent->_left = nullptr;
						}
						else {
							parent->_right = nullptr;
						}
						delete cur;
						cur = nullptr;
					}
					else if(cur->_right==nullptr) {
						if (cur->_data < parent->_data) {
							parent->_left = cur->_left;
							delete cur;
							cur = nullptr;
						}
						else{
							parent->_right = cur->_left;
							delete cur;
							cur = nullptr;
						}
					}
					else if (cur->_left==nullptr) {
						if (cur->_data < parent->_data) {
							parent->_left = cur->_right;
							delete cur;
							cur = nullptr;
						}
						else {
							parent->_right = cur->_right;
							delete cur;
							cur = nullptr;
						}
					}
					else {
						node* pa = cur->_right;
						while (pa->_left) {
							pa = pa->_left;
						}
						cur->_data = pa->_data;
						delete pa;
						pa = nullptr;
					}
					return true;
				}
			}
			return false;
		}
	private:
		void print(node* cur) {
			if (cur==nullptr) {
				return;
			}
			print(cur->_left);//想象二级图
			std::cout << cur->_data << " ";
			print(cur->_right);
		}
		node* _root;
	};
}

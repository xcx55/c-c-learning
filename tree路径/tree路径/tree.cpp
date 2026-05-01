#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"tree.h"
void test01(tree* a, tree* b, tree* c, tree* d, tree* e, tree* f) {
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
}
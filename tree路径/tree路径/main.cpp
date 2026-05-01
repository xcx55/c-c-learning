#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"tree.h"

int main() {
	tree q1;
	tree* nodea = q1.treenode('a');
	tree* nodeb = q1.treenode('b');
	tree* nodec = q1.treenode('c');
	tree* noded = q1.treenode('d');
	tree* nodee = q1.treenode('e');
	tree* nodef = q1.treenode('f');
	test01(nodea, nodeb, nodec, noded, nodee, nodef);
	treeprint1(nodea);

	return 0;
}
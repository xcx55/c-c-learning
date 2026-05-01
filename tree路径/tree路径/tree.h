#pragma once
#include<iostream>
#include<vector>

class Solution {
public:
    void Getsumleft(int* sum, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left && root->left->left == nullptr && root->left->right == nullptr) {
            (*sum) += root->left->val;
            return;
            бн        return sum;
        }
    };
void test01(tree* a, tree* b, tree* c, tree* d, tree* e, tree* f);
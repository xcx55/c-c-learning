#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = { 0 };
        int i = 0;
        for (auto e : s) {
            count[e - 97]++;
        }
        for (; i < s.size(); i++) {
            if (count[s[i]-97] == 1) {
                return i;
            }
        }
        return -1;
    }
};



int main() {
    Solution a;
    string q1("aabb");
    cout << a.firstUniqChar(q1) << endl;
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int x1 = num1.size() - 1;
        int x2 = num2.size() - 1;
        int size1 = num1.size();
        int size2 = num2.size();
        int carry = 0;
        int aa = 0;
        string s;
        while (size1 > 0 || size2 > 0) {
            int sum1 = x1 < 0 ? 0 : num1[x1] - '0';
            int sum2 = x2 < 0 ? 0 : num2[x2] - '0';
            int sum = sum1 + sum2 + carry;
            carry = sum / 10;
            aa = sum % 10;
            s += (aa+'0');
            aa = 0;
            sum = 0;
            x1--;;
            size1--;
            x2--;
            size2--;
    }
        if (carry > 0) {
            s += (carry+'0');
        }
    reverse(s.begin(), s.end());
    return s;
}
};

int main() {
    Solution a;
    string s("9111");
    string s1("911");
    string q1=a.addStrings(s,s1);
    cout << q1 << endl;
    return 0;
}
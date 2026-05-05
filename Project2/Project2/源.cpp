#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
bool issimu(const char& a) {
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
		return true;
	}
	return false;
}


	class Solution {
	public:
		bool iszimu(const char& a) {
			if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= 48 && a <= 57)) {
				return true;
			}
			return false;
		}
		bool isover(const char&a,const char&b) {
			if ((a>=48&&a<=57&&b>=65)||(b >= 48 && b <= 57 && a >= 65)){
				return true;
			}
			if (a == b) {
				return false;
			}
			else if (a == b + 32) {
				return false;
			}
			else if (a + 32 == b) {
				return false;
			}
			else
				return true;
		}
		bool isPalindrome(string s) {
			string::iterator st1 = s.begin();
			string::iterator st2 = s.end() - 1;
			while (st1 < st2) {
				while (st1 < st2 && !iszimu(*st1)) {
					++st1;
				}
				while (st1 < st2 && !iszimu(*st2)) {
					--st2;
				}
				if (this->isover(*st1,*st2)) {
					return false;
				}
				++st1;
				--st2;
			}
			return true;
		}
	};
	int main() {
		string s("0P");
		Solution s1;
		cout << s1.isPalindrome(s);
		return 0;
	}
	
	






	/*string s;
	cin >> s;
	size_t a = s.size() - 1;
	while (a > 0 && issimu(s[a])) {
		--a;
	}
	string s1(s.substr(a));
	cout << s1.length();*/
	
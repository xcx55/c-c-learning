#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
namespace s {
	class string {
	public:
		friend ostream& operator<<(ostream& out, const s::string& a);
		string(const char a[]) {//权限放大！！！
			size_t i = 0;
			while (a[i]!='\0') {
				++i;
			}
			char* pa = new char[i+1];
			i = 0;
			while (a[i]!= '\0') {
				*(pa + i) = a[i];
				++i;
			}
			pa[i] = '\0';
			top = i;
			capacity = i + 1;
			this->str = pa;
		}
		~string() {
			delete[] str;
		}
		const size_t size() {
			int count = 0;
			while (str[count]!='\0') {
				++count;
			}
			return count;
		}
	private:
		char* str;
		size_t top;
		size_t capacity;
	};
	ostream& operator<<(ostream& out, const s::string& a) {
		size_t c = 0;
		while (a.str[c]) {
			out << a.str[c];
			++c;
		}
		return out;
	}
}

int main() {
	s::string q1("hello");
	cout << q1;
	cout << q1.size();
	return 0;
}
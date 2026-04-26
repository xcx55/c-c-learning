#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include"yyds.h"
//int main() {
//	stack<int> q1;//1、要看到见域才能命名或破域！！
//	//2、访问函数在底层看来就是破域
//	//3、类就在模板的域生成
//	//4、访问量，就要是同域或者破域！！！
//	allocator
//	return 0;
//}

//int main() {
//	bit::stack<int> q1;
//	q1.push(1);
//	q1.bit::stack<int>::push(1);//要么全权交予编译器，要么自己手动全部输入
//	//char str[] = "asdfg";
//	//string s1("hello world");//调用类域构造函数,这个类就是string<char> string就是模板，对string<char>重命名为strjng这一类
//	////因为模板，所以就有该准确类域的函数生成，就可以调用，编译器能够直接看见就可以破域
//	//std::string s2("hello world");
//	//std::string s4(s2,0,2);
//	//cout << s4 << endl;
//	//return 0;
//}
int stringsuffix(const string&a) {
	return a.find('.');
}
  
vector<string> Get(string& url) {
	vector<string> v;
	size_t i1 = 0;
	if (url.find(':') != string::npos) {
		i1 = url.find(':');
		v.push_back(url.substr(0,i1-0));
		//左闭右开
	}
	size_t i2 = 0;
	if (url.find('/', i1 + 3) != string::npos) {
		i2 = url.find('/', i1 + 3);
		v.push_back(url.substr(i1+3,i2-i1-3));
		//左闭右开
	}
	v.push_back(url.substr(i2+1));
	return v;
}

//int main() {
//	string url("https://mp.csdn.net/?spm=1011.2480.3001.5448");
//	vector<string> a = Get(url);
//	cout << a[2] << endl;
//	return 0;
//}
string aa(string& num1,string& num2) {
		int x1 = num1.size() - 1;
		int x2 = num2.size() - 1;
		int size1 = num1.size();
		int size2 = num2.size();
		int carry = 0;
		string s;
		while (size1 > 0 || size2 > 0) {
			int sum1 = size1 <= 0 ? 0 : num1[x1] - '0';
			int sum2 = size2 <= 0 ? 0 : num2[x2] - '0';
			int sum = sum1 + sum2 + carry;
			carry = sum / 10;
			s += (sum % 10 + '0');
			sum = 0;
			size1--;
			size2--;
			x1--;
			x2--;
		}
		if (carry)
			s += carry;
		reverse(s.begin(), s.end());
		return s;
}
int main() {
	string s1("1");
	string s2("9");
	cout << aa(s1,s2) << endl;
	return 0;
}
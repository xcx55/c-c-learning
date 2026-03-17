#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;
class date {
public:
	date(int year=1,int month=1,int day=1);
	date operator-(int day);
	int monthday(int year,int month);
	void print() {
		cout << _year << " " << _month << " " << _day << " " << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
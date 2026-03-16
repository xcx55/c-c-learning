#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

class date {
public:
	date(int year=2020,int month=1,int day=1);
	date operator+(int day);
	date(const date&pa) {
		_year = pa._year;
		_month = pa._month;
		_day = pa._day;
	}
	void print();
	int monthday(int year,int day);
private:
	int _year;
	int _month;
	int _day;
};

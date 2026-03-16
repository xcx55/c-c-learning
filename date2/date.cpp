#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"date.h"

date::date(int year,int month,int day) {
	_year = year;
	_month = month;
	_day = day;
 }

int date::monthday(int year,int day) {
	int everymonthday[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int everymonthday2[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year%400==0||(year%4==0&&year%100==0)) {
		return everymonthday[_month];
	}
	else {
		return everymonthday2[_month];
	}
}



date date::operator+(int day) {
	date q2(*this);
	q2._day += day;
	while (date::monthday(q2._year,q2._month)<q2._day) {
		q2._day -= date::monthday(q2._year, q2._month);
		q2._month++;
		if (q2._month>12) {
			_month = 1;
			q2._year++;
		}
	}
	return q2;
}

void date::print() {
	cout << _year << " " << _month << " " << "  " << _day << endl;
}
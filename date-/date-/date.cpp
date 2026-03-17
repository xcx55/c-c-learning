#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"date.h"

date::date(int year,int month,int day) {
	this->_year = year;
	_month = month;
	_day = day;
}

int date::monthday(int year,int month) {//Öð×Ö½Ú¿½±´
	int ruenmonthday[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int pingmonthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return ruenmonthday[month];
	}
	else
		return pingmonthday[month];
	
}


date date::operator-(int day) {
	date q1(*this);
	q1._day -= day;
	while (q1._day<=0) {
		q1._day += monthday(q1._year,q1._month);
		q1._month--;
		if (q1._month==0) {
			q1._month = 12;
			q1._year--;
		}

	}
	return q1;
}
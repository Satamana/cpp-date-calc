#include "stdafx.h"
#include "date.h"
date::date(size_t d, size_t m, size_t y)
{
	this->year = (y >= 1) ? y : 0;
	this->month = (m >= 1 && m <= 12) ? m : 0;
	if ((this->month <= 7 && this->month % 2 != 0) || (this->month >= 8 && this->month % 2 == 0)) this->day = (d >= 1 && d <= 31) ? d : 0;
	else if (((this->month <= 7 && this->month % 2 == 0) || (this->month >= 8 && this->month % 2 != 0)) && this->month != 2) this->day = (d >= 1 && d <= 30) ? d : 0;
	else if ((this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0) && this->month == 2) this->day = (d >= 1 && d <= 29) ? d : 0;
	else if ((this->year % 4 != 0 && this->year % 100 == 0 || this->year % 400 != 0) && this->month == 2) this->day = (d >= 1 && d <= 28) ? d : 0;
}
size_t date::countdays()
{
	size_t days = this->day + (this->year - 1) * 365 + (this->year - 1) / 4 + (this->year - 1) / 400 - (this->year - 1) / 100;
	for (int i = 0; i < this->month - 1; i++)
	{
		days += 30;
		if ((i <= 6 && i % 2 == 0) || (i >= 7 && i % 2 != 0)) days++;
		if (i == 3) days -= (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0) ? 2 : 3;
	}
	return days;
}
size_t date::operator-(date &ob)
{
	return ((this->countdays() > ob.countdays())? this->countdays() - ob.countdays() : ob.countdays() - this->countdays());
}
date date::operator+(size_t days)
{
	int numdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (days / 365 != 0)
	{
		this->year += days / 365;
		days -= (days / 365) * 365;
	}
	if (days / 30 != 0)
	{
		int months = days / 30;
		days -= (days / 30) * 30;
		if (this->month + months > 12)
		{
			this->year++;
			this->month = this->month + months - 12;
		}
	}
	if (this->day + days > numdays[this->month - 1])
	{
		this->month++;
		this->day = (this->day + days) - numdays[this->month - 1];
	}
	this->day += days;
	return *this;
}
std::istream & operator>>(std::istream &os, date &ob)
{
	size_t d, m, y;
	do
	{
		std::cout << "Введите дату (дд мм гггг): ";
		os >> d >> m >> y;
		os.ignore();
		ob.year = (y >= 1) ? y : 0;
		ob.month = (m >= 1 && m <= 12) ? m : 0;
		if ((ob.month <= 7 && ob.month % 2 != 0) || (ob.month >= 8 && ob.month % 2 == 0)) ob.day = (d >= 1 && d <= 31) ? d : 0;
		else if (((ob.month <= 7 && ob.month % 2 == 0) || (ob.month >= 8 && ob.month % 2 != 0)) && ob.month != 2) ob.day = (d >= 1 && d <= 30) ? d : 0;
		else if ((ob.year % 4 == 0 && ob.year % 100 != 0 || ob.year % 400 == 0) && ob.month == 2) ob.day = (d >= 1 && d <= 29) ? d : 0;
		else if ((ob.year % 4 != 0 && ob.year % 100 == 0 || ob.year % 400 != 0) && ob.month == 2) ob.day = (d >= 1 && d <= 28) ? d : 0;
	} while (!ob.day || !ob.month || !ob.year);
	return os;
}
std::ostream & operator<<(std::ostream &os, date &ob)
{
	os << ob.day << "." << ob.month << "." << ob.year << std::endl;
	return os;
} 
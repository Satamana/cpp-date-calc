#pragma once9
class date
{
	size_t day = 0;
	size_t month = 0;
	size_t year = 0;
public:
	date() = default;
	date(size_t, size_t, size_t);
	size_t countdays();
	size_t operator-(date &);
	date operator+(size_t);
	friend std::istream & operator>>(std::istream &, date &);
	friend std::ostream & operator<<(std::ostream &, date &);
};
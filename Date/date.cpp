#include "date.h"
#include <time.h>
#include <string>

using namespace std;

const unsigned short int Date::MaxDaysOfMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const unsigned short int Date::table[13] = {0,399,430,93,124,154,185,215,246,277,307,338,368};

bool Date::isValid(unsigned short int day,unsigned short int month,unsigned short int year)
{
	if (month <= 12)
	{
		if(day <= (MaxDaysOfMonth[month]+((month ==2 && isLeapYear(year))?1:0)))
			return true;
	}
	return false;
}

bool Date::isLeapYear(unsigned short int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))?true:false;
}

bool Date::setDate(unsigned short int day,unsigned short int month,unsigned short int year)
{
	if(isValid(day,month,year))
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else
	{
		*this = getCurrDate();
	}
	return true;
}

int Date::compareTo(Date obj)
{
	if(this->year == obj.year && this->month == obj.month && this->day == obj.day)
	{
		return 0;
	}
	else
	{
		if(this->year >= obj.year)
		{
			if(this->month >= obj.month)
			{
				return(this->day > obj.day)?1:-1;	
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}
}

Date Date::getCurrDate()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	return Date(ltm->tm_mday,ltm->tm_mon,ltm->tm_year+1900);	
}

Date Date::operator+(int nDays)
{
	unsigned short int sD,sM,sY,nMaxDays;
	
	nMaxDays = (MaxDaysOfMonth[this->month]+((this->month == 2 && isLeapYear(this->year))?1:0));

	sD = this->day+nDays;
	sM = this->month;
	sY = this->year;

	while(sD > nMaxDays)
	{
		sD -= nMaxDays;
		++sM;
		if(sM > 12)
		{
			sM = 1;
			++sY;
		}
		nMaxDays = (MaxDaysOfMonth[sM]+((sM == 2 && isLeapYear(sY))?1:0));
	}
	return Date(sD,sM,sY);
}

Date Date::operator-(int nDays)
{
	unsigned short int sD,sM,sY,nMaxDays;

	nMaxDays = (MaxDaysOfMonth[this->month]+((this->month == 2 && isLeapYear(this->year))?1:0));

	sD = this->day - nDays;
	sM = this->month;
	sY = this->year;

	while(sD < 0)
	{
		sD += nMaxDays;
		--sM;
		if(sM < 1)
		{
			sM = 12;
			--sY;
			nMaxDays = (MaxDaysOfMonth[sM]+((sM == 2 && isLeapYear(sY))?1:0));
		}
	}
	return Date(sD,sM,sY);
}

int Date::operator-(Date obj)
{
	short int df = this->compareTo(obj);
	int nDays = 0;
	unsigned int nDb1,nDb2;

	Date dt = *this;

	switch(df)
	{
		case 0:	nDays = 0;
				break;

		case 1:	nDb1 = (this->year)*365 + (this->year)/4 - (this->year)/100 + (this->year)/400 + this->day + table[this->month];
				nDb2 = (obj.year)*365 + (obj.year)/4 - (obj.year)/100 + (obj.year)/400 + obj.day + table[obj.month];
				nDays = nDb1 - nDb2;
				break;

		case -1:nDb1 = (this->year)*365 + (this->year)/4 - (this->year)/100 + (this->year)/400 + this->day + table[this->month];
				nDb2 = (obj.year)*365 + (obj.year)/4 - (obj.year)/100 + (obj.year)/400 + obj.day + table[obj.month];
				nDays = nDb2 - nDb1;
				break;
	}
	return nDays;
}

string Date::toString()
{
	string date = to_string(this->day)+string("/")+to_string(this->month)+string("/")+to_string(this->year);
	return date; 	
}


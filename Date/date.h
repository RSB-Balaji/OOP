#include <string>
using namespace std;

class Date
{
 private:
	unsigned short int day;
	unsigned short int month;
	unsigned short int year;
	
	static const unsigned short int MaxDaysOfMonth[13];
	static const unsigned short int table[13];

	bool isValid(unsigned short int ,unsigned short int, unsigned short int );
	bool isLeapYear(unsigned short int );

 public:
	Date()
	{
		*this = getCurrDate(); 
	}

	Date(unsigned short int day,unsigned short int month,unsigned short int year)
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
	}

	Date(const Date &obj)
	{
		this->day = obj.day;
		this->month = obj.month;
		this->year = obj.year;
	}

	bool setDate(unsigned short int ,unsigned short int ,unsigned short int );
	int compareTo(Date );
	Date getCurrDate();
	Date operator+(int);
	Date operator-(int);
	int operator-(Date );
	string toString();
};

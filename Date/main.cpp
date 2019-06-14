#include <iostream>
#include "date.h"

using namespace std;

int main()
{
	Date obj1 = Date ();
	Date obj2 = Date(19,2,1999);
	obj1 = obj1 + 10;
	cout<<obj1.toString()<<endl;
	cout<<obj1.compareTo(obj2)<<endl;
	obj2 = obj2 - 10;
	cout<<obj2.toString()<<endl;
	cout<<(obj1 - obj2)<<endl;
	return 0;
}
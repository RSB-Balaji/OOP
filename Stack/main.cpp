#include<iostream>
#include "stack.h"
using namespace std;

int main()
{
	Stack<int> obj(5);
	obj.push(5);
	obj.push(10);
	cout<<obj.pop()<<endl;
	cout<<obj.pop()<<endl;
	cout<<obj.pop();
 return 0;
}

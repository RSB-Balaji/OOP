template <class T>
class Stack
{
 private:
	int top;
	int size;
	T *stack;
 public:
	Stack(int stackSize) 
	{ 
		size = stackSize;
		top = -1;
		stack = new T[stackSize];
	}	
	bool push(T );
	T pop();
	bool isEmpty();	
	bool isFull();
	int spaceLeft();
};

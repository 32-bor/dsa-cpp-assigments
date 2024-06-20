#include<iostream>
using namespace std;
#define INVALID_CAPACITY 1
#define STACK_OVERFLOW 2
#define STACK_UNDERFLOW 3

class Stack
{
	private:
		int capacity;
		int top;
		int *ptr;
	public:
		Stack(int);
		void push(int);
		int peek();
		void pop();
		~Stack();
		bool isFull();
		bool isEmpty();
		int size();
		void reverse();
		int min();
};

Stack::Stack(int capacity)
{
	try
	{
		if(capacity<0)
			throw INVALID_CAPACITY;
		this->capacity=capacity;
		top=-1;
		ptr=new int[capacity];
	}
	catch(int e)
	{
		cout<<"\nInvalid capacity";
		ptr=NULL;
	}
}

void Stack::push(int data)
{
	if(isFull())
		throw STACK_OVERFLOW
	else
	{
		top++;
		ptr[top]=data;
	}
}

int Stack::peek()
{
	if(isEmpty())
		throw STACK_UNDERFLOW;
	return top;
}

void Stack::pop()
{
	if(isEmpty())
		throw STACK_UNDERFLOW;
	top--;
}

Stack::~Stack()
{
	if(ptr!=NULL)
	{
		delete []ptr;
		ptr=NULL;
	}
}

bool Stack::isFull()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_STACK;
		else
			return top==capacity-1;
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}

bool Stack::isEmpty()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		else
			return top==-1;
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}

int Stack::size()
{
	return top+1;
}

void Stack::reverse()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		else
		{
			int i,j,temp
			for(i=0,j=top;i<=top/2;i++,j--)
			{
				int temp;
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}

int Stack::min()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		else
		{
			int minimum=ptr[0];
			for(i=1;i<=top;i++)
				if(ptr[i]<minimum)
					minimum=ptr[i];
			return minimum;
		}
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}

void Stack::reverseStack(Stack &s1)
{
	Stack s2(s1.size()),s3(s1.size());

	while(!s1.isEmpty())
	{
		s2.push(s1.peek());
		s1.pop();
	}
	while(!s2.isEmpty())
	{
		s3.push(s2.peek());
		s2.pop();
	}
	while(!s3.isEmpty())
	{
		s1.push(s3.peek())
		s3.pop();
	}
}

void minValue()
{
	Stack s1(10),minStack(10);
	
}




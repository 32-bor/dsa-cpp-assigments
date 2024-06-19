#include<iostream>
#include<string.h>
using namespace std;
#define INVALID_ARRAY 1
#define EMPTY_ARRAY 2
#define INVALID_INDEX 3

class Array
{
	private:
		int capacity;
		int lastIndex;
		int *ptr;
	public:
		Array(int);
		bool isEmpty();
		void append(int);
		void insert(int,int);
		void edit(int,int);
		void delete(int);
		bool isFull();
		int get(int);
		int count();
		~Array();
		int find(int);
};

Array::Array(int capacity)
{
	this->capacity=capacity;
	lastIndex=-1;
	ptr=new int[capacity];
}

bool Array::isEmpty()
{
	return lastIndex==-1;
}

void Array::append(int data)
{
	if(lastIndex<capacity-1)
	{
		lastIndex++;
		ptr[lastIndex]=data;
	}
}

void Array::insert(int index,int data)
{
	for(int i=lastIndex;i>=index;i++)
		ptr[i+1]=ptr[i];
	ptr[i]=data;
	lastIndex++;
}

void Array::edit(int index,int data)
{
	ptr[index]=data;
}

void Array::delete(int index)
{
	for(int i=index;i<lastIndex;i++)
		ptr[i]=ptr[i+1];
	lastIndex--;
}

bool Array::isFull()
{
	return lastIndex==capacity-1;
}

int Array::get(int index)
{
	return ptr[index];
}

int Array::count()
{
	return lastIndex+1;
}

Array::~Array()
{
	delete []ptr;
}

Array::find(int data)
{
	for(int i=0;i<=lastIndex;i++)
		if(ptr[i]==data)
			return i;
	return -1;
}





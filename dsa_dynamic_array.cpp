#include<iostream>
#include<string.h>
using namespace std;
#define INVALID_ARRAY 1
#define EMPTY_ARRAY 2
#define INVALID_INDEX 3
#define INVALID_CAPACITY 4

class DynArray
{
	private:
		int capacity;
		int lastIndex;
		int *ptr;
	public:
		DynArray(int);
		void doubleArray();
		void halfArray();
		int current_capacity();
		bool isEmpty();
		void append(int);
		void insert(int,int);
		void edit(int);
		void del(int);
		bool isFull(int);
		int get(int);
		int count();
		~DynArray();
		int find(int);

};

int DynArray::find(int element)
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		for(int i=0;i<=lastIndex;i++)
		{
			if(ptr[i]==element)
				return i;
		}
		return -1;
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}

DynArray::~DynArray()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		delete []ptr;
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}

int DynArray::count()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		else 
		{
			int i,n=0;
			for(i=0;i<=lastIndex;i++)
				n++;
		}
		return n;
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
		return -1;
	}
}

int DynArray::get(int index)
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		else if(index<0 || index>lastIndex+1)
			throw INVALID_INDEX;
		else
			return ptr[index];
	}
	catch(int e)
	{
		if(e==1)
			cout<<"\nInvalid array";
		else if(e==3)
			cout<<"\nInvalid index";
	}
}

bool DynArray::isFull(int)
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		return lastIndex==capacity-1;
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}

void DynArray::del(int index)
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		if(index<0 || index>lastIndex+1)
			throw INVALID_INDEX;
		for(int i=index;i<lastIndex;i++)
		{
			ptr[i]=ptr[i+1];
		}
		lastIndex--;
	}
	catch(int e)
	{
		if(e==1)
			cout<<"\nInvalid array";
		else if(e==3)
			cout<<"\nInvalid index";
	}
}

void DynArray::edit(int index)
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		if(index<0 || index>lastIndex+1)
			throw INVALID_INDEX;
		else 
			ptr[index]=data;
	}
	catch(int e)
	{
		if(e==1)
			cout<<"\nInvalid array";
		else if(e==3)
			cout<<"\nInvalid index";
	}
}

void DynArray::insert(int index, int data)
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		if(index<0 || index>lastIndex+1)
			throw INVALID_INDEX;
		doubleArray();
		for(int i=lastIndex;i>=index;i++)
		{
			ptr[i+1]=ptr[i];
		}
		ptr[index]=data;
		lastIndex++;
	}
	catch(int e)
	{
		if(e==1)
			cout<<"\nInvalid array";
		else if(e==3)
			cout<<"\nInvalid index";
	}
}

void DynArray::append(int data)
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		doubleArray();
		lastIndex++;
		ptr[lastIndex]=data;
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}

bool DynArray::isEmpty()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		return lastIndex==-1;
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}

int DynArray::current_capacity()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		return capacity;
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}

DynArray::DynArray(int capacity)
{
	try
	{
		if(capacity<0)
			throw INVALID_CAPACITY;
		this->capacity=capacity;
		lastIndex=-1;
		ptr=new int[capacity];
	}
	catch(int e)
	{
		cout<<"\nInvalid capacity";
		ptr=NULL;
	}
}

void DynArray::doubleArray()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;

		else if(lastIndex==capacity-1)
		{
			int *temp=new int[2*capacity];
			for(int i=0;i<=lastIndex;i++)
			{
				temp[i]=ptr[i];
			}
			delete []ptr;
			ptr=temp;
		}
		capacity=2*capacity; 
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}

void DynArray::halfArray()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;

		else if(lastIndex<capacity/2)
		{
			int *temp=new int[2*capacity];
			for(int i=0;i<=lastIndex;i++)
			{
				temp[i]=ptr[i];
			}
			delete []ptr;
			ptr=temp;
		}
		capacity=capacity/2; 
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
	}
}



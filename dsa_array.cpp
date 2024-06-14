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
		int last_index;
		int *ptr;
	public:
		Array(){ }
		Array(int);
		void createArray(int);
		bool isEmpty();
		void append(int);
		void insert(int,int);
		void edit(int,int);
		void deleteElement(int);
		bool isFull();
		int get(int);
		int count();
		~Array();
		int find(int);
		Array(Array&);
		void showData();
		Array& operator=(Array&);
};

int main()
{
	int i;
	Array obj(4);
	obj.append(10);
	obj.insert(0,20);
	obj.insert(0,30);
	Array a;
	a=obj;
	for(i=0;i<obj.count();i++)
	{
		cout<<obj.get(i)<<" ";
	}
	cout<<endl; 

	for(i=0;i<a.count();i++)
	{
		cout<<a.get(i)<<" ";
	}
	cout<<endl;
	return 0;
}

Array& Array::operator=(Array &arr)
{
	if(ptr!=NULL)
		delete []ptr;

	capacity=arr.capacity;
	last_index=arr.last_index;

	if(arr.ptr!=NULL)
	{
		ptr=new int[capacity];
		for(int i=0;i<capacity;i++)
		{
			ptr[i]=arr.ptr[i];
		}
		return *this;
	}
	else
	{
		ptr=NULL;
		return *this;
	}
}

Array::Array(Array &arr)
{
	int i;

	if(arr.ptr!=NULL)
	{
		capacity=arr.capacity;
		last_index=arr.last_index;
		cout<<capacity<< " "<<last_index<<endl;
		ptr=new int[5];
		for(i=0;i<capacity;i++)
		{
			ptr[i]=arr.ptr[i];
		}
	}
	else
	{
		ptr=NULL;
	}
}

int Array::find(int data)
{
	try
	{
		int i;
		if(ptr==NULL)
			throw INVALID_ARRAY;
		if(last_index<0)
			cout<<"\nEmpty array";
		else
		{
			for(i=0;i<=last_index;i++)
			{
				if(ptr[i]==data);
				return i;
			}
			return -1;
		}
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
		return -1;
	}
}

Array::~Array()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		delete []ptr;
	}
	catch(int e)
	{
		cout<<"\nInvalid Array";
	}
}

int Array::count()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		int i,n=0;
		for(i=0;i<=last_index;i++)
			n++;
		return n;
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
		return -1;
	}
}

int Array::get(int index)
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		if(index<0 || index>last_index)
			cout<<"\nInvalid index or Empty array";
		else
			return ptr[index];
	}
	catch(int e)
	{
		cout<<"\nInvalid array";
		return -1;
	}
}

bool Array::isFull()
{
	if(ptr==NULL)
		throw INVALID_ARRAY;
	return last_index==-1;
}

void Array::deleteElement(int index)
{
	int i;
	if(ptr==NULL)
		throw INVALID_ARRAY;
	if(index<0 || index >last_index)
		cout<<"\nInvalid index or Empty array";
	else
	{
		for(i=index;i<last_index;i++)
		{
			ptr[i]=ptr[i+1];
		}
		last_index--;
	}
}

void Array::edit(int index,int data)
{
	if(ptr==NULL)
		throw INVALID_ARRAY;
	if(index<0 || index>last_index)
		cout<<"\nInvalid index";
	else
		ptr[index]=data;
}

void Array::insert(int index, int data)
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		if(index<0 || index>last_index+1)
			throw INVALID_INDEX;
		if(last_index<capacity-1)
		{
			for(int i=last_index;i>=index;i--)
			{
				ptr[i+1]=ptr[i];
			}
			ptr[index]=data;
			last_index++;
		}
	}
	catch(int e)
	{
		if(e==1)
			cout<<"\nInvalid Array";
		else if(e==3)
			cout<<"\nInvalid index";
	}
}

void Array::createArray(int capacity)
{
	try
	{
		if(ptr==NULL)
		{
			if(capacity<0)
				throw INVALID_ARRAY;
			this->capacity=capacity;
			last_index=-1;
			ptr=new int[capacity];
		}
		else
		{
			// int x;
			// cout<<"Do you want to create a new array? \n 1/0\n";
			// cin>>x;
			// switch(int x)
			// {
			// case 1:
			// 	delete []ptr;
			// 	if(capacity<0)
			// 		throw INVALID_ARRAY;
			// 	this->capacity=capacity;
			// 	last_index=-1;
			// 	ptr=new int[capacity];
			// 	break;
			// case 0:
			// 	cout<<"\nNew array not created";
			// }
					delete []ptr;
				if(capacity<0)
					throw INVALID_ARRAY;
				this->capacity=capacity;
				last_index=-1;
				ptr=new int[capacity];
		}
	}
	catch(int e)
	{
		cout<<"\nInvalid capacity";
	}
}

void Array::append(int data)
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		if(last_index<capacity-1)
		{
			last_index++;
			ptr[last_index]=data;
		}
		else
			cout<<"\nArray overflow";
	}
	catch(int e)
	{
		cout<<"Invalid Array";
	}
}

Array::Array(int capacity)
{
	try
	{
		if(capacity<0)
			throw INVALID_ARRAY;
		this->capacity=capacity;
		last_index=-1;
		ptr=new int[capacity];
	}
	catch(int e)
	{
		cout<<"\nInvalid capacity";
		ptr=NULL;
	}
}

bool Array::isEmpty()
{
	try
	{
		if(ptr==NULL)
			throw INVALID_ARRAY;
		return last_index==-1;
	}

	catch(int e)
	{
		cout<<"\nInvalid array";
		return false;
	}
}

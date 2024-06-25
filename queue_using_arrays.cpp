#include<iostream>
using namespace std;
#define INVALID_CAPACITY 1

class Queue
{
	private:
		int capacity;
		int front;
		int rear;
		int *ptr;
	public:
		Queue(int);
		void enqueue(int);
		bool isEmpty();
		bool isFull();
		int getRear();
		int getFront();
		void dequeue();
		~Queue();
		int size();
};

Queue::Queue(int capacity)
{
	if(capacity<0)
		throw INVALID_CAPACITY;
	else
	{
		this->capacity=capacity;
		front=rear=-1;
		ptr=new int[capacity];
	}
	catch(int e)
	{
		cout<<"\nInvalid capacity";
		ptr=NULL;
	}
}

void Queue::enqueue(int data)
{
	if(!isFull())
	{
		if(rear==-1)
			front=rear=0;
		
		else if(rear==capacity-1)
			rear=0;
		else
			rear++;
		ptr[rear]=data;
	}
}

bool Queue::isEmpty()
{ 
	 return rear==-1;
}

bool Queue::isFull()
{
	if(front==0 && rear==capacity-1 || front==rear+1)
		return true;
	return false;
}

int Queue::getRear()
{
	if(ptr)
		return ptr[rear];
}

int Queue::getFront()
{
	if(ptr)
		return ptr[front];
}

void Queue::dequeue()
{
	if(!isEmpty())
	{
		if(front==rear)
			front=rear=-1;
		else if(front=capacity-1)
			front=0;
		else
			front++;
	}
}

Queue::~Queue()
{
	delete []ptr;
}

int Queue::size()
{
	if(rear<front)
		return capacity-front+rear+1;
	else
		return rear-front+1;
}






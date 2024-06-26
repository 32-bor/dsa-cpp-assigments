#include<iostream>
using namespace std;

struct Node
{
	int item;
	Node *next;
}

class Queue
{
	private:
		Node *front;
		Node *rear;
	public:
		Queue();
		void enqueue(int);
		int getRear();
		int getFront();
		void dequeue();
		~Queue();
		int size();
};

Queue::Queue()
{
	front=rear=NULL;
}

void Queue::enqueue(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	ptr->next=NULL;
	if(rear==NULL)
		front=rear=ptr;
	else 
	{
		rear->next=ptr;
		rear=ptr;
	}
}

int Queue::getRear()
{
	if(rear!=NULL)
		return rear->item;
}

int Queue::getFront()
{
	if(rear!=NULL)
		return front->item;
}

void Queue::dequeue()
{
	if(rear!=NULL)
	{
		Node *temp;
		temp=front;
		if(front==rear)
			front=rear=NULL;
		else
			  front=front->next;
		delete temp;
	}
}

Queue::~Queue()
{
	while(front)
		dequeue();
}

int Queue::size()
{
	int n=1;
	while(front)
	{
		front=front->next;
		n++;
	}
	return n;
}

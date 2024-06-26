#include<iostream>
using namespace std;

struct Node
{
	int item;
	Node *prev;
	Node *next;
}

class Deque
{
	private:
		Node *front;
		Node *rear;
	public:
		Deque();
		void insertFront(int);
		void insertRear(int);
		void deleteFront();
		void deleteRear();
		int getFront();
		int getRear();
		~Deque();
		bool isEmpty();
};

Deque::Deque()
{
	front=rear=NULL;
}

void Deque::insertFront(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	ptr->prev=NULL;
	ptr->next=front;
	if(front==NULL)
	{
		rear=ptr;
		front=ptr;
	}
	else
	{
		front->prev=ptr;
		front=ptr;
	}
}

void Deque::insertRear(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	ptr->next=NULL;
	ptr->prev=rear;
	if(rear==NULL)
	{
		front=ptr;
		rear=ptr;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
}

void Deque::deleteFront()
{
	if(front)
	{
		if(front==rear)
		{
			delete front;
			front=rear=NULL;
		}
		else
		{
			Node *temp=front;
			front->next->prev=NULL;
			front=front->next;
			delete temp;
		}
	}
}

void Deque::deleteRear()
{
	if(front)
	{
		if(front==rear)
		{
			delete rear;
			front=rear=NULL;
		}
		else
		{
			Nod e *temp;
			temp=rear;
			rear=rear->prev;
			rear->next=NULL;
			delete temp;
		}
	}
}

int Deque::getFront()
{
	if(front)
		return front->item;
}

int Deque::getRear()
{
	if(front)
		return rear->item;
}

Deque::~Deque()
{
	while(front)
		deleteFront();
}

bool Deque::isEmpty()
{
	return front==NULL;  
}
#include<iostream>
using namespace std;

struct Node
{
	int item;
	int pno;
	Node *next;
}

class PriorityQueue
{
	private:
		Node *start;
	public:
		PriorityQueue();
		void insert(int,int);
		void deleteItem();
		int getHighestPriorityElement();
		int getHighestPriorityNumber();
		~PriorityQueue();
		bool isEmpty();
};

PriorityQueue::PriorityQueue()
{
	start=NULL;
}

void PriorityQueue::insert(int p,int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	ptr->pno=p;
	Node *r=start;

	if(start==NULL)
	{
		start=ptr;
		ptr->next=NULL;
	}
	else if(start->pno<p)
	{
		ptr->next=start;
		start=ptr;
	}
	else
	{
		while(r)
		{
			if(r->next==NULL || r->next->pno<p)
				break;
			r=r->next;
		}
		ptr->next=r->next;
		r->next=ptr;
	}
}

void PriorityQueue::deleteItem()
{
	if(start)
	{
		Node *r=start;
		start=start->next;
		delete r;
	}
}

int PriorityQueue::getHighestPriorityElement()
{
	if(start)
	{
		return start->item;
	}
}

int PriorityQueue::getHighestPriorityNumber()
{
	if(start)
	{
		return start->pno;
	}
}

PriorityQueue::~PriorityQueue()
{
	while(start)
		deleteItem();
}

bool PriorityQueue::isEmpty()
{
	return start==NULL;
} 


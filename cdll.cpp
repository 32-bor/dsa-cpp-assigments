#include<iostream>
using namespace std;
struct Node
{
	Node *prev;
	  int item;
	Node *next;
}

class CDLL
{
	private:
		Node *start;
	public:
		 CDLL();
		 void insertAtStart(int);
		 void insertLast(int);
		 Node* search(int);
		 void insertAfter(Node*,int);
		 void deleteFirst();
		 void deleteLast();
		 void deleteNode();
		~CDLL();
};

CDLL::~CDLL()
{
	while(start->next!=start)
	{
		deleteFirst();
	}
	deleteFirst();
}

void CDLL::deleteNode(int data)
{
	Node *t=start;
	do
	{
		if(t->next->item==data)
		{
			Node *r=t->next;
			t->next=t->next->next;
			t->next->next->prev=t;
			delete r;
		}
		t=t->next;
	}while(t!=start)
}

void CDLL::deleteLast()
{
	if(start)
	{
		if(start->next==start)
		{
			delete start;
			start=NULL;
		}
		else
		{
			Node *r=start->prev;
			start->prev->prev->next=start;
			start->prev=start->prev->prev;
			delete r;
		}
	}
}

void CDLL::deleteFirst()
{
	if(start)
	{
		if(start->next==start)
		{
			delete start;
			start=NULL;
		}
		else
		{
			Node *r=start;
			start->prev->next=start->next;
			start->next->prev=start->prev;
			start=start->next;
			delete r;
		}
	}
}

void CDLL::insertAfter(Node *temp,int data)
{
	if(temp)
	{
		Node* ptr=new Node;
		ptr->item=data;
		ptr->next=temp->next;
		temp->next->prev=ptr;
		temp->next=ptr;
		ptr->prev=temp;
	}
}

Node* CDLL::search(int data)
{
	Node *t=start;
	do
	{
		if(t->item==data)
			return t;
		t=t->next;
	}while(t!=start)
	return NULL;
}

void CDLL::insertLast(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	if(start)
	{
		ptr->next=start;
		start->prev=ptr;
		start->prev->next=ptr;
		ptr->prev=start->prev;
	}
	else
	{
		ptr->next=ptr;
		ptr->prev=ptr;
		start=ptr;
	}
}

void CDLL::insertAtStart(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	if(start)
	{
		ptr->prev=start->prev;
		start->prev->next=ptr;
		ptr->next=start;
		start->prev=ptr;
		start=ptr;
	}
	else
	{
		ptr->next=ptr;
		ptr->prev=ptr;
		start=ptr;
	}
}

CDLL::CDLL()
{
	start=NULL;
}
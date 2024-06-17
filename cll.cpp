#include<iostream>
using namespace std;
struct Node
{
	  int item;
	Node *next;
}

class CLL
{
	private:
		Node *last;
	public:
		CLL();
		void insertAtStart(int);
		void insertEnd(int);
		Node* search(int);
		void insertAfter(Node*,int);
		void deleteFirst();
		void deleteLast();
		void deleteNode(int);
		~CLL();

};

CLL::~CLL()
{
	while(last)
		deleteFirst();
}

void deleteNode(int data)
{
	Node *t=last;

	if(last->item==data)
	{
		delete last;
		last=NULL;
	}
	else
	{
		while(t->next!=last)
		{
			if(t->next->item==data)
				break;
			t=t->next;
		}
		Node *r=t->next;
		t->next=t->next->next;
		delete r;
	}
}

void CLL::deleteLast()
{
	if(last)
	{
		if(last->next==last)
		{
			delete last;
			last=NULL;
		}
		else
		{
			Node *t=new Node;
			while(t->next!=last)
				t=t->next;
			t->next=last->next;
			delete last;
			last=t;
		}
	}
}

void CLL::deleteFirst()
{
	if(last)
	{
		if(last->next==last)
		{
			delete last;
			last=NULL;
		}
		else
		{
			Node *r=last->next;
			last->next=last->next->next;
			delete r;
		}
	}
}

void CLL::insertAfter(Node *temp,int data)
{
	if(temp)
	{
		Node *ptr=new Node;
		ptr->item=data;
		ptr->next=temp->next;
		temp->next=ptr;
	}
}

void CLL::search(int data)
{
	if(last)
	{
		Node *t=last;
		while(t->next!=last)
		{
			if(t->item)
				return t;
			t=t->next;
		}
		if(t->item==data)
			return t;
		else
			return NULL;
	}
}

void CLL::insertEnd(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	if(last)
	{
		ptr->next=last->next;
		last->next=ptr;
		last=ptr;
	}
	else
	{
		last=ptr;
		ptr->next=last;
	}
}

void CLL::insertAtStart(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	if(last)
	{
		ptr->next=last->next;
		last->next=ptr;
	}
	else
	{
		last=ptr;
		ptr->next=last;
	}
}

CLL::CLL()
{
	last=Null;
}
#include<iostream>
#include<string.h>
using namespace std;
#define LIST_EMPTY 1

struct Node
{
	Node *prev;
	  int item;
	Node *next;
};

class DLL
{
	private:
		Node *start;
	public:
		DLL();
		void insertAtStart(int);
		void insertLast(int);
		Node* search(int);
		void insertAfter(Node *,int);
		void deleteFirst();
		void deleteLast();
		void deleteNode(int);
		~DLL();
		void printDLL();
};

int main()
{
	DLL d;
	d.insertAtStart(10);
	d.insertLast(20);
	d.insertAfter(d.search(20),30);
	d.printDLL();
	cout<<endl;
	return 0;
}

void DLL::printDLL()
{
	if(start)
	{
		Node *t=start;
		while(t)
		{
			cout<<t->item<<" ";
			t=t->next;
		}
	}
}

DLL::~DLL()
{
	while(start)
		deleteFirst();
}

void DLL::deleteNode(int data)
{
	if(start)
	{
		if(start->next==NULL && start->item==data)
		{
			delete start;
			start=NULL;
		}
		else
		{
			Node *t=start;
			while(t)
			{	
				if(t->next->item==data)
				{
					Node *r=t->next;
					t->next=t->next->next;
					if(t->next->next)
						t->next->next->prev=t;
					delete r;
					break;
				}
				t=t->next;
			}
		}
	}
}

void DLL::deleteLast()
{
	Node *t=start;
	if(start)
	{
		if(start->next==NULL)
		{
			delete start;
			start=NULL;
		}
		else
		{
			while(t->next->next!=NULL)
				t=t->next;
			delete t->next;
			t->next=NULL;
		}
	}
}

void DLL::deleteFirst()
{
	if(start)
	{
		Node *r=start;
		if(start->next)
			start->next->prev=NULL;
		start=start->next;
		delete r;
	}
}

void DLL::insertAfter(Node *temp,int data)
{
	Node *ptr;
	if(temp)
	{
		ptr=new Node;
		ptr->item=data;
		ptr->prev=temp;
		ptr->next=temp->next;
		temp->next=ptr;
		if(temp->next)
			temp->next->prev=ptr;
	}
}

Node* DLL::search(int data)
{
	if(start)
	{
		Node *t=start;
		while(t)
		{
			if(t->item==data)
				return t;
			t=t->next;
		}
	}
	else
		return NULL;
}

void DLL::insertLast(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	ptr->next=NULL;
	
	if(start)
	{
		Node *t=start;
		while(t->next!=NULL)
			t=t->next;
		t->next=ptr;
		ptr->prev=t;
	}
	else
	{
		start=ptr;
		ptr->prev=NULL;	
	}
}

void DLL::insertAtStart(int data)
{
	Node *ptr=new Node;
	ptr->prev=NULL;
	ptr->item=data;
	ptr->next=start;
	if(start!=NULL)
		start->prev=ptr;
	start=ptr;
}

DLL::DLL()
{
	start=NULL;
}
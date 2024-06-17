#include<iostream>
#include<string.h>
using namespace std;
#define LIST_EMPTY 1

struct Node
{
	  int item;
	Node *next;
}

class SLL
{
	private:
		Node *Start;
	public:
		SLL();
		void insertAtStart(int);
		void insertAtLast(int);
		void insertAfter(Node*,int);
		Node* search(int);
		void deleteFirst();
		void deleteLast();
		void deleteNode(int);
		void deleteNodeAlternate(int);
		~SLL();
};

void SLL::deleteNodeAlternate(int key)
{
	
}

SLL::~SLL()
{
	while(Start)
		deleteFirst();
}

void SLL::deleteNode(int key)
{

	if(Start)
	{
		if(Start->next==NULL && Start->item==key)
		{
			delete Start;
			Start=NULL;
		}
		else
		{
			Node *t=Start;
			while(t)
			{
				if(t->next->item==key)
				{
					Node *r=t->next;
					t->next=t->next->next;
					delete r;
					break;
				}
				t=t->next;
			}
		}
	}
}

void SLL::deleteLast()
{
	try
	{
		if(Start)
			throw LIST_EMPTY;
		else if(Start->next)
		{
			delete Start;
			Start=NULL;
		}
		else
		{
			Node *t=Start;
			while(t->next->next)
				t=t->next;
			delete t->next;
			t->next=NULL;
		}
	}
	catch(int e)
	{
		cout<<"\nLinked list is empty";
	}
}

void SLL::deleteFirst()
{
	try
	{
		if(Start)
			throw LIST_EMPTY;
		else 
		{
			Node *r=Start;
			Start=Start->next;
			delete r;
		}
	}
	catch(int e)
	{
		cout<<"\nLinked list is empty";
	}
}

void SLL::insertAfter(Node *t,int key)
{
	if(t)
	{
		Node *ptr=new Node;
		ptr->item=key;
		ptr->next=t->next;
		t->next=ptr;
	}  
}

Node* SLL::search(int key)
{
	try
	{
		if(Start==NULL)
			throw LIST_EMPTY;
		else
		{
			Node *t=Start;
			while(t)
			{
				if(t->item==key)
					return t;
				t=t->next;
			}
			return NULL;
		}
	}
	catch(int e)
	{
		cout<<"\nLinked list is empty";
		return NULL;
	}
}

void SLL::insertAtLast(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	ptr->next=NULL;
	if(Start==NULL)
		Start=ptr;
	else
	{
		Node *t=Start;
		while(t->next!=NULL)
			t=t->next;
		t->next=ptr;
	}
}

void SLL::insertAtStart(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	ptr->next=NULL;
	Start=ptr;
}

SLL::SLL()
{
	 Start=NULL;
}
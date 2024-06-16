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
		~SLL();
};

SLL::~SLL()
{
	while(Start)
		deleteFirst();
}

void SLL::deleteNode(int key)
{
	try
	{
		if(Start==NULL)
			throw LIST_EMPTY;
		else if(Start->item==key)
			Start=NULL;
		else
		{
			Node *temp=Start;
			for(int i=0;temp->next->item!=key;i++)
			{
				temp=temp->next;
			}
			if(temp->next->next==NULL)
				temp->next=NULL;
			else
				temp->next=temp->next->next;
		}
	}
	catch(int e)
	{
		cout<<"\nLinked list is empty"
	}
}

void SLL::deleteLast()
{
	try
	{
		if(Start==NULL)
			throw LIST_EMPTY;
		else if(Start->next==NULL)
			Start==NULL;
		else
		{
			Node *temp=Start;
			for(int i=0;temp->next->next!=NULL;i++)
				temp->next=NULL;
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
		if(Start==NULL)
			throw LIST_EMPTY;
		else if(Start->next==NULL)
			Start=NULL;
		else 
			Start=Start->next;
	}
	catch(int e)
	{
		cout<<"\nLinked list is empty";
	}
}

void SLL::insertAfter(Node *temp,int key)
{
	Node *ptr=new Node;
	ptr->item=key;

	if(temp->next==NULL)
	{
		ptr->next=NULL;
		temp->next=ptr;
	}
	else
	{
		ptr->next=temp->next;
		temp->next=ptr;
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
			Node*temp=Start;
			for(int i=0;temp->next!=NULL;i++)
			{
				if(temp->item==key)
					return temp;
				temp=temp->next;
			}
			return NULL;
		}
	}
	catch(int e)
	{
		cout<<"\nLined list is empty";
	}
}

void SLL::insertAtLast(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	ptr->next=NULL;

	if(Start==NULL)
		Start=ptr;
	else if(Start->next==NULL)
		Start->next=ptr;
	else
	{
		Node *temp=Start;
		for(int i=0;temp->next!=NULL;i++)
			temp=temp->next;
		temp->next=ptr;
	}
}

void SLL::insertAtStart(int data)
{
	if(Start==NULL)
	{
		Node *ptr=new Node;
		ptr->item=data;
		ptr->next=NULL;
		Start=ptr;
	}
	else
	{
		Node *ptr=new Node;
		ptr->item=data;
		ptr->next=Start;
		Start=ptr;
	}
}

SLL::SLL()
{
	 Start=NULL;
}
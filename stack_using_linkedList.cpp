#include<iostream>
using namespace std;
#define STACK_EMPTY 1

class Node
{
	public:
		int item;
		Node *next;
};

class Stack
{
	private:
		Node *top;
	public:
		Stack();
		void push(int);
		int peek();
		int pop();
		bool isEmpty();
		~Stack();
		void reverseStack();
};

Stack::Stack()
{
	top=NULL;
}

void Stack::push(int data)
{
	Node *ptr=new Node;
	ptr->item=data;
	ptr->next=top;
	top=ptr;
}

int Stack::peek()
{
	if(top==NULL)
		throw STACK_EMPTY;
	return top->item;
}

int Stack::pop()
{
	if(top==NULL)
		throw STACK_EMPTY;
	Node *r=top;
	int temp=top->item;
	top=top->next;
	delete r;   
	return temp; 
}

bool Stack::isEmpty()
{
	return top==NULL;
}

Stack::~Stack()
{
	while(top)
		pop();
}

void Stack::reverseStack()
{
	Stack s2,t;
	t.top=top;

	while(top)
	{
		s2.push(pop());
	}
	top=s2.top;

	while(t.top)
	{
		t.pop();
	}
}

Stack* reverseStackAlt(Stack *s)
{
	Stack *stkptr=new Stack;
	while(!(s->isEmpty()))
	{
		stkptr->push(s->pop());
	}
	return stkptr;
}

bool isPalindrome(Stack *s)
{

}


#include<iostream>
using namespace std;
void printNatural(int);
void printNaturalReverse(int);
void printOddNatural(int);
void printOddNaturalReverse(int);
void printEvenNatural(int);
void printEvenNaturalReverse(int);
void printSquares(int);
void printSquaresReverse(int);
void printCubes(int);
void printCubesReverse(int);

void printCubesReverse(int n)
{
	if(n==1)
	{
		cout<<n*n*n<<" ";
		printCubesReverse(n-1);
	}
}

void printCubes(int n)
{
	if(n>0)
	{
		printCubes(n-1);
		cout<<n*n*n<<" ";
	}
}

void printSquaresReverse(int n)
{
	if(n>0)
	{
		cout<<n*n<<" ";
		printSquaresReverse(n-1);
	}
}

void printSquares(int n)
{
	if(n>0)
	{
		printSquares(n-1);
		cout<<n*n<<" ";
	}
}

void printEvenNaturalReverse(int n)
{
	if(n>0)
	{
		cout<<2*n<<" ";
		printEvenNaturalReverse(n-1);
	}
}

void printEvenNatural(int n)
{
	if(n>0)
	{
		printEvenNatural(n-1);
		cout<<2*n<<" ";
	}
}

void printOddNaturalReverse(int n)
{
	if(n>0)
	{
		cout<<2*n-1<<" ";
		printOddNaturalReverse(n-1);
	}
}

void printOddNatural(int n)
{
	if(n>0)
	{
		printOddNatural(n-1);
		cout<<2*n-1<<" ";
	}
}

void printNaturalReverse(int n)
{
	if(n>0)
	{
		cout<<n<<" ";
		printNaturalReverse(n-1);
	}
}

void printNatural(int n)
{
	if(n>0)
	{
		printNatural(n-1);
		cout<<n<<" ";
	}
}


int main()
{
	int n;
	cout<<"Enter a no\n";
	cin>>n;
	printCubesReverse(n);
	cout<<endl;
	return 0;
}
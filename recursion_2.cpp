#include<iostream>
using namespace std;
int sumNatural(int);
int sumOddNatural(int);
int sumEvenNatural(int);
int sumSquares(int);
int factorial(int);
int sumDigits(int);
void DecimalToBinary(int);
void DecimalToOctal(int);
int Fibonacci(int);
int hcf(int,int);
double power(double,double);

int hcf(int a,int b)
{
	if(a>b)
	{
		if(a%b==0)
			return b;
		return hcf(a%b,b);
	}
	else
	{
		if(b%a==0)
			return a;
		return hcf(a,b%a);
	}
}

double power(double x,double y)
{
	if(y==0)
		return 1;
	if(y>0)
		return x*power(x,y-1);
	else
		return 1/x*power(x,y+1);
}

int Fibonacci(int n)
{
	if(n==0 || n==1)
		return 0;
	else if(n==2)
		return 1;
	return Fibonacci(n-1) + Fibonacci(n-2);
}

void DecimalToOctal(int n)
{
	if(n>0)
	{
		DecimalToOctal(n/8);
		cout<<n%8;
	}
}

void DecimalToBinary(int n)
{
	if(n>0)
	{
		DecimalToBinary(n/2);
		cout<<n%2;
	}
}

int sumDigits(int n)
{
	if(n>=0 && n<=9)
		return n;
	return n%10+sumDigits(n/10);
}

int factorial(int n)
{
	if(n==0)
		return 1;
	return n*factorial(n-1);
}

int sumSquares(int n)
{
	if(n==1)
		return 1;
	return n*n+sumSquares(n-1);
}

int sumEvenNatural(int n)
{
	if(n==1)
		return 2;
	return 2*n+sumEvenNatural(n-1);
}

int sumOddNatural(int n)
{
	if(n==1)
		return 1;
	return 2*n-1 + sumOddNatural(n-1);
}

int sumNatural(int n)
{
	if(n==1)
		return 1;
	return n+sumNatural(n-1);
}

int main()
{ 
	double x;
	double y;
	cout<<"Enter two nos\n";
	cin>>x>>y;
	cout<<power(x,y);
	cout<<endl;
	return 0;
}
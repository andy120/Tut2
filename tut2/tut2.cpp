// Comptut2 2015.cpp : Defines the entry point for the console application.
//211543957

//Include libraries


#include <iostream>
#include <cmath>

using namespace std;

//Fraction structure definition
struct Fraction
{
	int numerator;
	int denominator;
};

//function prototypes
Fraction Create(int, int);
int gcd(int n, int d);
void Display(Fraction);
Fraction Sum(Fraction a, Fraction b);
Fraction Subtract(Fraction a, Fraction b);
Fraction Multiply(Fraction a, Fraction b);
Fraction Divide(Fraction a, Fraction b);

//main function to test program
int  main()
{
	//declare variables
	Fraction a, b, result;
	int num, denom;

	cout << "Enter fractions in the form  [ numerator SPACE denominator] :" << endl << endl;

	//prompt user to enter first fraction
	cout << "Enter the first fraction :" << endl;
	//get value of deneminator and numerator
	cin >> num >> denom;
	//create fraction
	a = Create(num, denom);

	//prompt user to eneter next fraction
	cout << "Enter the second fraction :" << endl;
	//get value of deneminator and numerator
	cin >> num >> denom;
	//create fraction object
	b = Create(num, denom);

	//add , subtract ,multiply and divide a and b and display results
	result = Sum(a, b);
	cout << "The sum of " << a.numerator << "/" << a.denominator << " and " << b.numerator << "/" << b.denominator << " is:  ";
	Display(result);

	result = Subtract(a, b);
	cout << "The difference of " << a.numerator << "/" << a.denominator << " and " << b.numerator << "/" << b.denominator << " is:  ";
	Display(result);

	result = Multiply(a, b);
	cout << "The product of " << a.numerator << "/" << a.denominator << " and " << b.numerator << "/" << b.denominator << " is:  ";
	Display(result);

	result = Divide(a, b);
	cout << "The division of " << a.numerator << "/" << a.denominator << " and " << b.numerator << "/" << b.denominator << " is:  ";
	Display(result);


	//pause display
	system("pause");
	//show that program executed successfully
	return 0;
}

//function to display fractions
void Display(Fraction temp)
{
	if (temp.denominator == 1)		//check if denominator is 1
		cout << temp.numerator << endl;
	else if (abs(temp.numerator) > abs(temp.denominator))	//check if fraction is a mixed fraction
		cout << temp.numerator / temp.denominator << " " << temp.numerator%temp.denominator << "/" << temp.denominator << endl;
	else if (temp.denominator<0)//remove negative sign from denominator
		cout << -1 * temp.numerator << "/" << -1 * temp.denominator << endl;
	else
		cout << temp.numerator << "/" << temp.denominator << endl;
}


//gcd got from Source C#:
int gcd(int n, int d)
{
	int remainder;
	while (d != 0)
	{
		remainder = n % d;
		n = d;
		d = remainder;
	}
	return n;
}

//function to create fractions
Fraction Create(const int n, const int d)
{
	Fraction c;
	c.numerator = n;

	if (d != 0)
		c.denominator = d;
	else
	{
		cout << "Error . Your can not divide by zero" << endl;
		exit(0);
	}
	return c;
}


//function definitions to add , subtract , multiply and divide fractions
Fraction Sum(Fraction a, Fraction b)
{
	int n = a.numerator*b.denominator + a.denominator*b.numerator;
	int d = a.denominator*b.denominator;
	return Create(n / gcd(n, d), d / gcd(n, d));
}

Fraction Subtract(Fraction a, Fraction b)
{
	int n = a.numerator*b.denominator - a.denominator*b.numerator;
	int d = a.denominator*b.denominator;
	return Create(n / gcd(n, d), d / gcd(n, d));
}

Fraction Multiply(Fraction a, Fraction b)
{
	int n = a.numerator*b.numerator;
	int d = a.denominator*b.denominator;
	return Create(n / gcd(n, d), d / gcd(n, d));
}
Fraction Divide(Fraction a, Fraction b)
{
	int n = a.numerator*b.denominator;
	int d = a.denominator*b.numerator;
	return Create(n / gcd(n, d), d / gcd(n, d));
}



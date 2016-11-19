#include <iostream>

using namespace std;

int calculate(int a, int b)
{
	a = a*2;
	b = b*3;	


	return (a+b); 

}


int main()
{
	int x=10;
	int y=20;
	
	cout<<"The value of x is: "<<x<<endl;
	cout<<"The value of y is: "<<y<<endl;



	int final=calculate(x, y);

	cout<<"The final value is "<<final;

	cout<<"The original values are "<<x<<" and "<<y;


	
	return 0;



}

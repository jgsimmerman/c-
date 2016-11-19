/*  lab1Part3 USC CSCI 102 -- Data Structures

Modify the "calculate" function such that it returns the value of the equation 2*a + 3*b (using the values pointed to by a & b).
Do the multiplications in such a way that they directly modify the values pointed to by the a & b that were passed in.

You main function should print out the initial values of x & y, call the calculate function with x & y as arguments and then print
out the final values of x & y after the call to "calculate". DO NOT change the original definitions of x & y.
*/
#include <iostream>

using namespace std;

int calculate(int* a, int* b)
{
    (*a) *= 2;
    (*b) *= 3;

    return (*a + *b);

}

int main()
{
	int x = 10;
	int y = 20;
	int final;


	cout<<"The value of x is: "<<x<<endl;
	cout<<"The value of y is: "<<y<<endl;



	final=calculate(&x, &y);

	cout<<"The final value is "<<final<<endl;

	cout<<"The original values are "<<x<<" and "<<y;



	return 0;


}

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int i;

	for (i=1; i <= 100; i++)
	{
		int x = (i/3), y = (i/5);

		if((x*3)== i) cout<<" Fizz"<<endl;
		else if((y*5)== i) cout<<" Buzz"<<endl;
		else cout<<i<<endl;
	}

	return 0;

}

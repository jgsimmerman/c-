#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int i;

	for (i=1; i <= 100; i++)
	{
		int x = (i/3), y = (i/5);

		if((i%3)== 0) cout<<" Fizz"<<endl;
		else if((i%5)== 0) cout<<" Buzz"<<endl;
		else cout<<i<<endl;
	}

	return 0;

}

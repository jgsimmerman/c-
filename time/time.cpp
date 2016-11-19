#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	time_t time1 = time(NULL);

	cout<<"Unix System Time: "<<time1<<endl;
	cout<<endl;
	
	double minutes = time1/60;
	cout<<"Minutes: "<<minutes<<endl;	
	
	double hours = minutes/60;
	cout<<"Hours: "<<hours<<endl;

	double days = hours/24;
	cout<<"Days: "<<days<<endl;

	double years = days/365.25;
	cout<<"Years: "<<years<<endl;

	int initTime = time(NULL) + 3;
	cout<<"initTime "<<initTime<<endl;
	
	return 0;
}

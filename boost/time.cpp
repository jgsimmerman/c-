#include <iostream>
#include "boost/date_time/gregorian/gregorian_types.hpp"

using namespace std;

int main()
{
	date d(day_clock::local_day()), d2(day_clock::universal_day());

	cout<<"Local Day: "<<d<<endl;
	cout<<"Universal Day: "<<d2<<endl;

	return 0;
}


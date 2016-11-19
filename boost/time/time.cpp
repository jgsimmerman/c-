#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"

//using namespace std;
//using namespace boost::gregorian;


int main()
{
	using namespace boost::gregorian;
	
	date d = day_clock::local_day();
	date d2 = day_clock::universal_day();

	std::cout<<"Local Day: "<<d<<std::endl;
	std::cout<<"Universal Day: "<<d2<<std::endl;

	std::cout<<"Universal Day + 2: "<<d2+2<<std::endl;

	return 0;
}


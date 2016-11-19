#include "algorithm.h"


//Need more Constructors?????????????????
Algorithm::Algorithm(bool a)
{
	answer = a;
	if(answer == true)
	{
		box++;
		setDayIncrement();
	}
	else
	{
		box = 1;
		setDayIncrement();
	}
}
//Mutator Functions
void Algorithm::setAnswer(bool a)
{
	answer = a;
}

void Algorithm::setBox(int b)
{
	box = b;
}

void Algorithm::setDayIncrement()
{
	if(box == 1) {dayIncrement = 1;}
	else if (box == 2) {dayIncrement = 3;}
	else if (box == 3) {dayIncrement = 10;}
	else if (box == 4) {dayIncrement = 30;}
	else {dayIncrement = 60;}
}

void Algorithm::setInterval(int dayIncrement)
{
	int interval = dayIncrement * 86400; //86400 seconds per day
}

bool Algorithm::getAnswer()
	{return answer;}

int Algorithm::getBox()
	{return box;}

int Algorithm::getDayIncrement()
	{return dayIncrement;}

int Algorithm::getInterval()
	{return interval;}

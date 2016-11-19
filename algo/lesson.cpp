#include <string>
#include <time.h>
#include <vector>

#include "lesson.h"

//add constructor and destructor


        /*Unfinished Mutator Functions*****************************/
void Lesson::setTopic(string address)
{//IS This Correct???????????????????
        string *topic = new string(address);
}

void Lesson::setTitle(string t)
{
        title = t;
}

void Lesson::setQuestions(vector <string> v)
{
        questions = v;
}

void Lesson::setAnswer(string a)
{
        answer = a;
}

        /*Time Mutator Functions************************/
void Lesson::setInitTime()
{	//is this right???????????????????????????????????????????
	initTime = time(NULL);
}

void Lesson::setRepeatTime(int interval)
{	//is this right???????????????????????????????????????????
	repeatTime = time(NULL) + interval;
}

void Lesson::setRepeat()
{
	time_t time1 = time(NULL);
	if(time1 < repeatTime) 
		{repeat = false;}
	else 
		{repeat = true;}
}

void Lesson::Algorithm(bool c)
{
	correct = c;
	if(correct == true)
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
void Lesson::setCorrect(bool c)
{
	correct = c;
}

void Lesson::setBox(int b)
{
	box = b;
}

void Lesson::setDayIncrement()
{
	if(box == 1) {dayIncrement = 1;}
	else if (box == 2) {dayIncrement = 3;}
	else if (box == 3) {dayIncrement = 10;}
	else if (box == 4) {dayIncrement = 30;}
	else {dayIncrement = 60;}
}

void Lesson::setInterval(int dayIncrement)
{
	int interval = dayIncrement * 86400; //86400 seconds per day
}

bool Lesson::getCorrect()
	{return correct ;}


int Lesson::getBox()
	{return box;}

int Lesson::getDayIncrement()
	{return dayIncrement;}

int Lesson::getInterval()
	{return interval;}

/*Time Accessor Functions***************************/
int Lesson::getInitTime()
        {return initTime;}

int Lesson::getRepeatTime()
        {return repeatTime;}

bool Lesson::getRepeat()
        {return repeat;}

        /*Need to do Topic and Question Accessor Functions****************/
string Lesson::getTopic()
        {return topic;}

string Lesson::getTitle()
        {return title;}

vector Lesson::getQuestions()
        {return questions;}

string Lesson::getAnswer()
        {return answer;}


#include <string>
#include <time.h>

#include "question.h"
#include "algorithm.h"
#include "objectTime.h"

//add constructor and destructor


        /*Unfinished Mutator Functions*****************************/
void ObjectTime::setTopic(string address)
{//IS This Correct???????????????????
        string *topic = new string(address);
}

void ObjectTime::setTitle(string t)
{
        title = t;
}
        
	/*Time Mutator Functions************************/
void ObjectTime::setInitTime()
{	//is this right???????????????????????????????????????????
	initTime = time(NULL);
}

void ObjectTime::setRepeatTime(int interval)
{	//is this right???????????????????????????????????????????
	repeatTime = time(NULL) + interval;
}

void ObjectTime::setRepeat()
{
	time_t time1 = time(NULL);
	if(time1 < repeatTime) 
		{repeat = false;}
	else 
		{repeat = true;}
}

/*Time Accessor Functions***************************/
int ObjectTime::getInitTime()
        {return initTime;}

int ObjectTime::getRepeatTime()
        {return repeatTime;}

bool ObjectTime::getRepeat()
        {return repeat;}

        /*Need to do Topic and Question Accessor Functions****************/
string ObjectTime::getTopic()
        {return topic;}

string ObjectTime::getTitle()
        {return title;}

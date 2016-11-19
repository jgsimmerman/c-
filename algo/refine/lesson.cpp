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
        

        /*Need to do Topic and Question Accessor Functions****************/
string ObjectTime::getTopic()
        {return topic;}

string ObjectTime::getTitle()
        {return title;}

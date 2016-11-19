#ifndef OBJECTTIME_H
#define OBJECTTIME_H	

#include <string>
#include <vector>

#include "question.h"
#include "algorithm.h"


using namespace std;

class ObjectTime 
{
        protected:
		string topic; //location of the topic
		string answer;
		string title;

	/* Question Variables ******************/
		Question questions;

        /*Time Variables************************/
		int initTime;
		int repeatTime;
		bool repeat;


        /*Unfinished Mutator Functions*****************************/
        public:
		void setTopic(string address);
       		void setTitle(string t);
        	void setQuestions(string, string, string, string, string);
	
        	void setInitTime();
		void setRepeatTime(int interval);
		void setRepeat();
		int getInitTime();
            	int getRepeatTime();
           	bool getRepeat();
            
        /*Need to do Topic and Question Accessor Functions****************/
        	string getTopic();
       		string getTitle();
            	Question getQuestions();
		
};

#endif





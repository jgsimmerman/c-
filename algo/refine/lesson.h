#ifndef LESSON_H
#define LESSON_H	

#include <string>
#include <vector>

#include "question.h"
#include "algorithm.h"


using namespace std;

class ObjectTime 
{
        protected:
		string topic; //location of the topic
		string title;

	/* Question Variables ******************/
		Question questions;
		string qFile; //location of Questions file
	
		Algorithm data;

        /*Unfinished Mutator Functions*****************************/
        public:
		void setTopic(string address);
       		void setTitle(string t);
        	void setQFile(string);
		void setQuestions(string);
	

        /*Need to do Topic and Question Accessor Functions****************/
        	string getTopic();
       		string getTitle();
		string getQFile();            	

		Question getQuestions();
		
};

#endif





#ifndef OBJECTTIME_H
#define OBJECTTIME_H	

#include <string>
#include <vector>

#include "question.h"

using namespace std;

class ObjectTime 
{
        protected:
		string topic; //location of the topic
		//vector <string> questions;
		string answer;
		string title;

	/* Question Variables ******************/
/*		string question1;
		string question2;
		string question3;
		string question4;
		string answer;
*/		Question questions;

        /*Time Variables************************/
		int initTime;
		int repeatTime;
		bool repeat;


        /*Unfinished Mutator Functions*****************************/
        public:
		void setTopic(string address);
       		void setTitle(string t);
        	void setQuestions(string, string, string, string, string);
	
		/*
		void setAnswer(string a);
		void setQuestion1(string);
		void setQuestion2(string);
		void setQuestion3(string);
		void setQuestion4(string);
		*/

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
		
		/*
		string getAnswer();  
		string getQuestion1();
		string getQuestion2();
		string getQuestion3();
		string getQuestion4();
		*/          
      /*   public static void main(String[] args)
         {
             Calendar calendar1 = Calendar.getInstance();

             ObjectTime test = new ObjectTime();

             int day = calendar1.get(Calendar.DAY_OF_YEAR);
             test.setInitTime();

             int interval=3;
             test.setRepeatTime(interval);

             System.out.println("Initial Time: " + test.getInitTime());
             System.out.println("Repeat Time: " + test.getRepeatTime());
             System.out.println("Lesson to be repeated today: " + test.getRepeat());
         }
	*/
};

#endif





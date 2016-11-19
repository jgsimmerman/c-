#ifndef LESSON_H
#define LESSON_H	

#include <string>
#include <vector>
using namespace std;

class Lesson 
{
        protected:
		string topic; //location of the topic
        	vector <string> questions;  //inherit a lesson class?
		string answer;

		string title;

        /*Time Variables************************/
		int initTime;
		int repeatTime;
		bool repeat;
	
	protected:
		bool correct;
		int box;
		int dayIncrement;
		int interval;

	public:
		void Algorithm(bool);
		
		void setCorrect(bool);
		void setBox(int);
		void setDayIncrement();
		void setInterval(int);

		bool getCorrect();
		int getBox();
		int getDayIncrement();
		int getInterval();


        /*Unfinished Mutator Functions*****************************/
        public:
		void setTopic(string address);
       		void setTitle(string t);
        	void setQuestions(vector v);
		void setAnswer(string a);

        	void setInitTime();
		void setRepeatTime(int interval);
		void setRepeat();
		int getInitTime();
            	int getRepeatTime();
           	bool getRepeat();
            
        /*Need to do Topic and Question Accessor Functions****************/
        	string getTopic();
       		string getTitle();
            	vector getQuestions();
		string getAnswer();            
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





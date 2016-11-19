#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

class Question
{
	protected:
		string question1;
		string question2;
		string question3;
		string question4;
	
		string answer;

	public:
		Question();
		Question(string);

		void setQuestion1(string);
		void setQuestion2(string);
		void setQuestion3(string);
		void setQuestion4(string);
		void setAnswer(string);

		string getQuestion1();
		string getQuestion2();
		string getQuestion3();
		string getQuestion4();
		string getAnswer();
		

};


#endif

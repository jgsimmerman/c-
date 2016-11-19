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
		Question(string q1, string q2, string q3, string q4, string a);

		

};


#endif

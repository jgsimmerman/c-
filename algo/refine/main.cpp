#include <iostream>
#include <string>
#include "question.h"

using namespace std;

int main()
{
	string input = "test.txt";
	Question test =	Question(input);
	
	cout<<test.getQuestion1()<<endl;
	cout<<test.getQuestion2()<<endl;
	cout<<test.getQuestion3()<<endl;
	cout<<test.getQuestion4()<<endl;
	cout<<test.getAnswer()<<endl;
		
	return 0;
}

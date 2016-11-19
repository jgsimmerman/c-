#include <iostream>
#include <vector>
#include <fstream>
#include "question.h"

using namespace std;

Question::Question()
{
	
}

Question::Question(string f)
{
	string fileName = f;
	
	fstream inFile;
	inFile.open(fileName.c_str());

	//process istream data
	string q1, q2, q3, q4;
	string a;
	//is this right????
	getline(inFile, q1);
	getline(inFile, q2);
	getline(inFile, q3);
        getline(inFile, q4);
	getline(inFile, a);

	setQuestion1(q1);
	setQuestion2(q2);
	setQuestion3(q3);
	setQuestion4(q4);
	setAnswer(a);	

	inFile.close();
}

void Question::setQuestion1(string q1)
{
	question1 = q1;
}

void Question::setQuestion2(string q2)
{
	question2 = q2;
}

void Question::setQuestion3(string q3)
{
	question3 = q3;
}

void Question::setQuestion4(string q4)
{
	question4 = q4;
}

void Question::setAnswer(string a)
{
	answer = a;
}

string Question::getQuestion1()
	{return question1;}

string Question::getQuestion2()
	{return question2;}

string Question::getQuestion3()
	{return question3;}
	
string Question::getQuestion4()
	{return question4;}

string Question::getAnswer()
	{return answer;}

#ifndef ALGORITHM_H
#define ALGORITHM_H

class Algorithm
{

	protected:
		bool answer;
		int box;
		int dayIncrement;
		int interval;

	public:
		Algorithm(bool);
		
		void setAnswer(bool);
		void setBox(int);
		void setDayIncrement();
		void setInterval(int);

		bool getAnswer();
		int getBox();
		int getDayIncrement();
		int getInterval();

};

#endif
	

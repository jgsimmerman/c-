#ifndef ALGORITHM_H
#define ALGORITHM_H

class Algorithm
{

	protected:
		bool answer;
		int box;
		int dayIncrement;
		int interval;
		
		/*Time Variables************************/
                int initTime;
                int repeatTime;
                bool repeat;

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
		
		/*Time Mutators and Accesors*/
		void setInitTime();
                void setRepeatTime(int interval);
                void setRepeat();
                
		int getInitTime();
                int getRepeatTime();
                bool getRepeat();

		
};

#endif
	

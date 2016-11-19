/**
A header file of utility functions.

@author Brent Nash (University of Southern California, Fall 2010)
*/

#ifndef UTILITY_H_
#define UTILITY_H_

/**
	Generate a random number between 0 and x.
	
	@pre None
	@post None
	
	@param x The upper bound on the random number to generate. 
	If not specified, x will default to 999.
	
	@return This function will return a random number between 0 and x (inclusive).  
*/
int getRandomNumber(int x=999);

/**
	Generate a random number between "start" and "end" (inclusive).
	
	@pre None
	@post None
	
	@param start The lower bound on the random number to generate.
	@param end The upper bound on the random number to generate.
	
	@return A random number X such that start <= X <= end.
	
	@throw out_of_range If start is greater than end
*/
int getRandomNumber(int start,int end);

#endif

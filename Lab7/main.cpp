/**
@author Brent Nash (University of Southern California, Fall 2010)

@mainpage CSCI 102 Conway's Game of Life
 
@section description Description

This application provides a basic framework for building Conway's Game of Life
based on the QT GUI framework in C++.
*/

#include <QApplication>
#include "gridwindow.h"

using namespace std;

/** The default number of rows in the grid. */
#define ROWS 10
/** The default number of columns in the grid. */
#define COLS 20

/**
	A simple main method to create the window class
	and then pop it up on the screen.
	
	@param argc The number of command line arguments passed in.
	@param argv The array of command line arguments passed in.
	
	@return 0 if application exiting successfuly, non-zero otherwise.
*/
int main(int argc, char *argv[])
{
	//create the overall windowed application
	QApplication app(argc, argv);

	//create the actual window
	GridWindow widget(NULL,ROWS,COLS);
    
    //pop the window up on the screen
    widget.show();
    
    //go into the visualization loop
    return app.exec();
}

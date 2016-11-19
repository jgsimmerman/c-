/**
@author Brent Nash (University of Southern California, Fall 2010)
*/

#include <iostream>

#include "gridwindow.h"

using namespace std;

/* Constant for the title text displayed in the GUI */
#define WINDOW_TITLE "Conway's Game of Life"

/*
	The constructor for the window.  It constructs the three
	portions of the GUI and then lays them out vertically.
*/
GridWindow::GridWindow(QWidget *parent,int rows,int cols)
: QWidget(parent), cells(rows,cols)
{
	//Setup the title at the top
 	setupHeader();
 	
 	//Setup the grid of colored cells in the middle
 	setupGrid();
 	
 	//Setup the row of buttons across the bottom
 	setupButtonRow();

 	//put everything together
 	this->windowLayout = new QVBoxLayout();
 	windowLayout->addLayout(headerLayout);
 	windowLayout->addLayout(gridLayout);
 	windowLayout->addLayout(buttonLayout);
	setLayout(windowLayout);
}

GridWindow::~GridWindow()
{
	delete this->title;
	delete this->headerLayout;
	delete this->gridLayout;
	delete this->buttonLayout;
	delete this->windowLayout;
	
	//There are actually some things right now that we're using "new" to
	//create, but not using "delete" to clean up
}

/*
	Build the header section of the GUI.  As of right now,
	all the header contains is a single centered text field.
*/
void GridWindow::setupHeader()
{
	//make a new horizontal box layout
	this->headerLayout = new QHBoxLayout();
	this->headerLayout->setAlignment(Qt::AlignHCenter);
	
	//make a regular label field, center it and
	//make it in a large, bold font
	this->title = new QLabel(WINDOW_TITLE,this);
 	this->title->setAlignment(Qt::AlignHCenter);
 	this->title->setFont(QFont("Times", 26, QFont::Bold));
 	
 	//add the label widget to the layout
 	this->headerLayout->addWidget(this->title);
}

/*
	Build the grid of cells.  There's a lot of heavy
	lifting going on in this function.  This function
	populates the grid's 2D array of GridCells with
	an MxN set of cells where M = rows and N = cols.
*/
void GridWindow::setupGrid()
{
	//create a grid layout
	this->gridLayout = new QGridLayout();
	
	//tell the grid there should be no empty
	//space between cells (we want the cells to
	//bump right up against each other)
 	this->gridLayout->setHorizontalSpacing(0);
 	this->gridLayout->setVerticalSpacing(0);
 	this->gridLayout->setSpacing(0);
 	this->gridLayout->setAlignment(Qt::AlignHCenter);
 	
 	for(unsigned int i=0; i < this->cells.getRows(); i++)
 	{
 		for(unsigned int j=0; j < this->cells.getCols(); j++)
 		{
 			//create a new cell and add it to the existing row
 			GridCell* gridCell = new GridCell();
 			
 			//add the cell to the grid layout and set the column
 			//to expand vertically
 			this->gridLayout->addWidget(gridCell,i,j);
 			this->gridLayout->setColumnStretch(j,1);
 			
 			this->cells[i][j] = gridCell;
 		}
 		//set each row to expand horizontally too
		this->gridLayout->setRowStretch(i,1);
 	}
}

/*
	Build the footer section of the GUI.  Right now, this
	section just contains a horizontal row of buttons.
*/
void GridWindow::setupButtonRow()
{
	//create a horizontal box to hold all the buttons
	this->buttonLayout = new QHBoxLayout();
	this->buttonLayout->setAlignment(Qt::AlignHCenter);
	
 	//create a button to set all the cells in the grid to "empty"
 	//make the button appear as a fixed size visually
 	//connect a "click" on the "clear" button to the "handleClear" function in this class
 	//add the button to the horizontal box of buttons
 	QPushButton *clearButton = new QPushButton("Clear");
 	clearButton->setFixedSize(100,25); //width,height in pixels
 	connect(clearButton, SIGNAL(clicked()), this, SLOT(handleClear())); 	
 	this->buttonLayout->addWidget(clearButton);


	QPushButton *randomizeButton = new QPushButton("Randomize");
	randomizeButton->setFixedSize(100,25); //width, height in pixels
	connect(randomizeButton, SIGNAL(clicked()), this, SLOT(handleRandomize()));
	this->buttonLayout->addWidget(randomizeButton);

 	
 	//create a button to quit the application
	//make the button appear as a fixed size visually
 	//connect a "click" on the "exit" button to the "quit" function of the overall application
 	//(qApp is a global pointer to the single QApplication instance of the QT application)
	//add the button to the horizontal box of buttons
 	QPushButton *quitButton = new QPushButton("Exit");
	quitButton->setFixedSize(100,25); //width,height in pixels
	connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit())); 	
 	this->buttonLayout->addWidget(quitButton);
 	
 	//////////////////////////
 	//TODO: Modify this function for Lab 7 Part 5
 	//////////////////////////
}

/*
	A SLOT function for handling clicks on the "clear" button. This function
	will receive "clicked" signals on the "Clear" button and then set all
	the values of the cells in the grid to DEAD.
*/
void GridWindow::handleClear()
{
	//loop through all the rows in the grid
	for(unsigned int row=0; row < cells.getRows(); row++)
	{
		//loop through all the cells in the current row
		for(unsigned int col=0; col < cells.getCols(); col++)
		{
			//grab the current cell & set its value to empty
			GridCell *cell = cells[row][col];
			cell->setType(DEAD);
		}
	}
}


void GridWindow::handleRandomize()
{
	//loop through all the rows in the grid
        for(unsigned int row=0; row < cells.getRows(); row++)
        {
                //loop through all the cells in the current row
                for(unsigned int col=0; col < cells.getCols(); col++)
                {
                        //grab the current cell & set its value to empty
                        GridCell *cell = cells[row][col];
                        cell->randomizeCell();
                }
        }
}

Grid<GridCell*>& GridWindow::getCells()
{
	return this->cells;
}

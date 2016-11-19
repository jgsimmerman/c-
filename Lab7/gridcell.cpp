/**
@author Brent Nash (University of Southern California, Fall 2010)
*/

#include <iostream>

#include "gridcell.h"
#include "utility.h"

using namespace std;

GridCell::GridCell(QWidget *parent)
: QFrame(parent)
{ 
	//cells default to DEAD until changed
	this->type = DEAD;
	
	//Set the frame style.  This is what gives each box its black border.
	setFrameStyle(QFrame::Box);
	
	//Create the button that takes up the entirety of each grid cell
	//Make it so the cells automatically expand to fill the area as the window grows/shrinks
	//Make sure the button is never drawn smaller than 25x25 pixels
	this->button = new QPushButton(this);
	this->button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	this->button->setMinimumSize(25,25); //width,height in pixels
	
	//Create a simple layout to hold our button and add the button to it
	this->layout = new QHBoxLayout();
	layout->addWidget(this->button);
	setLayout(layout);
	
	//We want the buttons to expand all the way to the edges of the current
	//frame with no space leftover
	layout->setStretchFactor(this->button,1);
	layout->setContentsMargins(0,0,0,0);
	layout->setSpacing(0);
	
	//tie together a "clicked" signal on the button to the "handleClick"
	//slot function of this class
	connect(this->button,SIGNAL(clicked()),this,SLOT(handleClick()));
	
	redrawCell();
}

GridCell::~GridCell()
{
	delete this->button;
	delete this->layout;
}

CellState GridCell::getType() const
{
	return(this->type);
}

void GridCell::setType(CellState type)
{
	//change the cell type and redraw the cell on the GUI
	//(changing the type might change the drawn appearance of the cell)
	this->type = type;
	redrawCell();
	typeChanged(type);
}

/*
	Handler slot for button clicks.  This method is
	called whenever the user clicks on this cell in
	the grid.
*/
void GridCell::handleClick()
{
	//////////////////////////
	//TODO: Modify this method for Lab 7 Part 4
 	//////////////////////////	
	
	cout << "You clicked on a cell!" << endl;

	randomizeCell();
}
		
/*
	Convience method that will look at the type of
	the current cell and return the appropriate color
	for that type.  Feel free to change this if you don't
	like our colors!
*/
Qt::GlobalColor GridCell::getColorForCellState()
{
	switch(this->type)
	{
		default:
		case DEAD:
			return Qt::white;
		case ALIVE:
			return Qt::black;
	}
}
		
/*
	Helper method to force the current cell to be redrawn on
	the GUI.  This method is automatically called whenever the
	"setType(...)" method is invoked.
*/
void GridCell::redrawCell()
{
	//Find out what color this cell should be
	Qt::GlobalColor gc = getColorForCellState();
	
	//Force the button in the cell to be the proper color
	this->button->setPalette(QPalette(gc,gc));
	this->button->setAutoFillBackground(true);
	
	//Force QT to NOT draw the borders on the button
	this->button->setFlat(true);
}

void GridCell::randomizeCell()
{
	//generate a random value
	int rand=getRandomNumber();
	CellState randValue;	
	if( rand%2 == 0) randValue = DEAD;
	else randValue = ALIVE;

	setType(randValue);
}

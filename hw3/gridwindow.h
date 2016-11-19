#ifndef MAZEWINDOW_H_
#define MAZEWINDOW_H_

#include <vector>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QApplication>

#include "grid.h"
#include "gridcell.h"
#include "cellstate.h"

/**
This is the class representing the whole window that comes up
when this program runs.  It contains a header section with
a title, a middle section that is a grid full of MxN cells and
a bottom section who has a row of buttons.

This class "is-a" QWidget (inherits from the QT widget object).

@author Brent Nash (University of Southern California, Fall 2010)
*/
class GridWindow : public QWidget
{
	//Macro to allow this object to have signals & slots
	Q_OBJECT
	
	private:
	
		/** A 2D collection of pointers to all the cells in the Grid. */
		Grid<GridCell*> cells;
		
		/** A pointer to the title text on the window. */
		QLabel *title;
		
		/* The layout for the header (top 1/3) of the GUI. */
		QHBoxLayout *headerLayout;
		
		/* The layout for the middle grid section (middle 1/3) of the GUI. */
 		QGridLayout *gridLayout;
 		
 		/* The layout for the button row (bottom 1/3) of the GUI. */
 		QHBoxLayout *buttonLayout;
 		
 		/* The layout for the entire application. */
 		QVBoxLayout *windowLayout;
		
	public slots:
		
		/* A handler for a click of the clear button. */
		void handleClear();

		/* A handler for a click of the randomize button. */
		void handleRandomize();
	
	public:
	
		/**
		Constructor for building a grid window object
		
		@param parent A pointer to the parent widget of this widget (default NULL if this
		is the top-level widget).
		@param rows The number of rows in the grid (default 3).
		@param cols The number of columns in the grid (default 3).
		*/
		GridWindow(QWidget *parent = NULL,int rows=3,int cols=3);
		
		/**
			Destructor for Grid Window to clean up all dynamically allocated GUI objects.
		*/
		~GridWindow();
		
		/**
			Accessor for the actual Grid of cells.
			
			@return A reference to the actual cell grid being used.
		*/
		Grid<GridCell*>& getCells();
		
	private:
	
		/**
			Helper function to construct the GUI header layout including creating all
			sub-widgets of this section.
		*/
		void setupHeader();
		
		/**
			Helper function to construct the grid layout section of the GUI including creating
			all sub-widgets of this section.
		*/
		void setupGrid();
		
		/**
			Helper function to construct the GUI bottom row button layout including creating all
			sub-widgets of this section.
		*/
		void setupButtonRow();
};
 
#endif

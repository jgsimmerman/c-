#ifndef GRIDCELL_H_
#define GRIDCELL_H_

#include <QPalette>
#include <QColor>
#include <QPushButton>
#include <Qt>
#include <QWidget>
#include <QFrame>
#include <QHBoxLayout>
#include <iostream>

#include "cellstate.h"

/**
A class representing a single cell in a grid.  Each cell is implemented
as a QT QFrame that contains a single QPushButton.  The button is sized
so that it takes up the entire frame.  Each cell also keeps track of what
type of cell it is based on the CellState enum.

This class "is-a" QFrame (inherits from the QT frame object).

@author Brent Nash (University of Southern California, Fall 2010)
*/
class GridCell : public QFrame
{
	//macro allowing us to have signals & slots on this object
	Q_OBJECT

	private:
	
		/** The button inside the cell that gives its clickability. */
		QPushButton* button;
		/** The type of this cell (alive or dead). */
		CellState type;
		/** The horizontal layout used to put "button" in this frame. */
		QHBoxLayout *layout;
		
	public slots:
		
		/** Callback for handling a click on the current cell. */
		void handleClick();
		
		/**
		Simple mutator for the cell type
		(don't worry about it being a slot, it still works like a normal
		setter method.). This method also calls the "redrawCell" function.
		
		@param type The type of cell based on the CellState enum. The state determines
		how the cell is actually drawn.
		*/
		void setType(CellState type);
	
	signals:
		/**
		A signal to notify listeners when the type of this cell has changed.
		(as of right now, this is not used anywhere). It's just a hook in case
		we want to use it.
		
		@param type The CellState enum instance specifying what state the current
		grid cell has changed to.
		*/
		void typeChanged(CellState type);
	
	public:
	
		/**
		Constructor for creating a cell.  Take in the parent widget or default
		the parent to NULL to start. 
		
		@param parent The parent widget of this widget if there is one (default NULL).
		*/
		GridCell(QWidget *parent = NULL);
		
		/**
			Basic destructor to clean up dynamic variables.
		*/
		virtual ~GridCell();
		
		/**
		Force the cell to be redrawn.  
		
		Also automatically called behind the scenes by the
		setType(...) function.
		*/
		void redrawCell();
		
		/**
			Accessor for the cell type.
			
			@return Returns the instance of the CellState enum corresponding to the
			type of this particular grid cell.
		*/
		CellState getType() const;


		void randomizeCell();
		
	private:
		
		/**
		Helper method to return the color that this cell should be based
		on the value of its type.
		
		@return The QT color that is assigned to the cell based on the cell's type.
		*/
		Qt::GlobalColor getColorForCellState();
};

#endif

#ifndef CELLTYPE_H_
#define CELLTYPE_H_

/**
An enum representing the different states a cell can have. The cell
type maps directly to how the cell will be colored when drawn. Currently,
cells can only be ALIVE or DEAD.
	
@author Brent Nash (University of Southern California, Fall 2010)

*/
enum CellState
{
	DEAD,
	ALIVE
};

#endif

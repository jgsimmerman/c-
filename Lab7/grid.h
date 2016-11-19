#ifndef GRID_H_
#define GRID_H_

#include <vector>
#include <stdexcept>

/**
A header file with a templated version of
a "Grid" class which is like an objectified version
of a 2-dimensional array (picture a Tic-Tac-Toe board,
Minesweeper or a checkerboard).  A Grid consists of
M rows and N columns.  Once a Grid is created, its
size never changes.

There are many ways to access a grid cell:

grid[row][col] - will retrieve the element at (row,col), but
will NOT check range boundaries.

grid(row,col) - will retrieve the element at (row,col) and check ranges.

grid.at(row,col) - will retrieve the element at (row,col) and check ranges.

@author Brent Nash (University of Southern California, Fall 2010)
*/
template <typename T>
class Grid
{
	private:
		
		/** A 2-dimensional array of data */
		T** data;
		/** The number of rows in the table */
		unsigned int rows;
		/** The number of cols in the table */
		unsigned int cols;
		
	public:
	
		/**
			Create an instance of the grid.
			
			@param rows The number of rows that will be in the grid.
			@param cols The number of columns that will be in the grid.
		*/
		Grid(unsigned int rows, unsigned int cols);
		
		/**
			Copy constructor for the grid. Performs a deep copy.
			
			@param other The grid to copy into this grid.
		*/
		Grid(const Grid& other);
		
		/**
			Destructor to clean up the backing dynamic memory of the grid.
		*/	
		~Grid();
		
		/**
			Overloaded = operator for the grid.  Performs a deep copy.
			
			@param other The grid to set this grid equal to.
			@return A reference to the current Grid object (a.k.a. "this").
		*/
		Grid<T>& operator=(const Grid<T>& other);
		
		/**
			Mutable overloaded () operator that allows the user to access a grid cell
			in the manner:
			
			grid(0,0) //access grid cell (0,0)
			
			@param row The row number of the cell to access.
			@param col The column number of the cell to access.
			@return A reference to the current value at cell (row,col).
			@throw out_of_range If row or col is outside the bounds of the grid.
		*/
		T& operator() (unsigned int row, unsigned int col);
		
		/**
			Mutable overloaded [] operator that allows the user to access a grid cell
			in the manner:
			
			grid[0][0] //access grid cell (0,0)
			
			No range checking is done!
			
			@param row The row number of the row to access.
			@return A reference to the backing array for the ENTIRE ROW "row" in the grid (we provided the
			backing [][] operator in an unsafe fashion by allowing the user to index directly
			into the raw array behind the scenes).
		*/
		T*& operator[](unsigned int row);
		
		/**
			Cell accessor that allows the user to access a grid cell
			in the manner:
			
			grid.at(0,0) //access grid cell (0,0)
			
			@param row The row number of the cell to access.
			@param col The column number of the cell to access.
			@return A reference to the current value at cell (row,col).
			@throw out_of_range If row or col is outside the bounds of the grid.
		*/
		T& at(unsigned int row,unsigned int col);
		
		/**
			Cell mutator that allows the user to set the value of a grid
			cell in the manner:
			
			grid.set(0,0,value) //set grid cell (0,0) to "value"
			
			@param row The row number of the cell to access.
			@param col The column number of the cell to access.
			@param value The new value to set into the grid at (row,col)
			@throw out_of_range If row or col is outside the bounds of the grid.
		*/
		void set(unsigned int row,unsigned int col,const T& value);
		
		/**
			Accessor for the number of rows.
			
			@return The number of rows in the grid.
		*/
		unsigned int getRows() const;
		
		/**
			Accessor for the number of columns.
			
			@return The number of columns in the grid.
		*/
		unsigned int getCols() const;
		
		/**
			Accessor for the number of cells in the grid.
			
			@return The total number of cells in the grid (rows * cols).
		*/
		unsigned int size() const;
		
	private:
	
		/**
			Convenience function to copy "other"'s contents
			into the current Grid object.  Used by the copy constructor
			and operator= functions.
			
			@param other The Grid object whose contents should be copied into this one.
		*/
		void copy(const Grid<T>& other);
		
		/**
			Convenience function to destroy the dynamic memory used
			by this object.  Used by the destructor and operator=.
		*/
		void destroy();
};

template <typename T>
Grid<T>::Grid(unsigned int rows,unsigned int cols)
{
	this->rows = rows;
	this->cols = cols;
	
	//this is how you have to initialize a 2D array
	//(The "rows" array is an array of arrays, one per column)
	this->data = new T*[rows];
	for(unsigned int i=0; i < rows; i++)
	{
		this->data[i] = new T[cols];
	}
}

template <typename T>
Grid<T>::Grid(const Grid<T>& other)
{
	//Since this is a constructor, there are currently
	//no initial values for these fields, so we're not actually
	//creating a memory leak here
	this->data = NULL;
	this->rows = 0;
	this->cols = 0;
	
	copy(other);
}

template <typename T>
Grid<T>& Grid<T>::operator=(const Grid<T>& other)
{
	//avoid self-copying
	if(this != &other)
	{
		copy(other);
	}

	//allow = operator chaining
	return *this;
}

template <typename T>
Grid<T>::~Grid()
{
	destroy();
}

template <typename T>
void Grid<T>::destroy()
{
	//if data is NULL, there's nothing to destroy
	//(shortcut for the copy constructor)
	if(this->data == NULL)
	{
		return;
	}
	
	//first delete all the column arrays, then the row array
	for(unsigned int i=0; i < this->rows; i++)
	{
		delete [] this->data[i];
	}
	delete [] this->data;
	
	this->rows = 0;
	this->cols = 0;
}

template <typename T>
void Grid<T>::copy(const Grid<T>& other)
{
	//For the operator=, we need to destroy the current used
	//memory before making new memory for the copy
	destroy();
	
	this->rows = other.rows;
	this->cols = other.cols;
	
	//Reallocate this grid to be the same size as "other", then
	//copy over all the data contents
	this->data = new T*[rows];
	for(unsigned int i=0; i < this->rows; i++)
	{
		this->data[i] = new T[cols];
		for(unsigned int j=0; j < this->cols; j++)
		{
			this->data[i][j] = other.data[i][j];
		}
	}
}

template <typename T>
T& Grid<T>::operator()(unsigned int row, unsigned int col)
{
	return(at(row,col));
}
		
template <typename T>
T*& Grid<T>::operator[](unsigned int row)
{
	//Actually returning a reference to the entire row array
	return(this->data[row]);
}

template <typename T>
T& Grid<T>::at(unsigned int row,unsigned int col)
{
	//do bounds checking on the input row/col
	if(row < 0 || row >= this->rows)
	{
		throw std::out_of_range("Input row was out of bounds!");
	}
	else if(col < 0 || col >= this->cols)
	{
		throw std::out_of_range("Input col was out of bounds!");
	}
	
	return(this->data[row][col]);
}

template <typename T>
void Grid<T>::set(unsigned int row,unsigned int col,const T& value)
{
	//do bounds checking on the input row/col
	if(row < 0 || row >= this->rows)
	{
		throw std::out_of_range("Input row was out of bounds!");
	}
	else if(col < 0 || col >= this->cols)
	{
		throw std::out_of_range("Input col was out of bounds!");
	}
	
	this->data[row][col] = value;
}

template <typename T>
unsigned int Grid<T>::getRows() const
{ 
	return(this->rows);
}

template <typename T>
unsigned int Grid<T>::getCols() const
{ 
	return(this->cols); 
}

template <typename T>
unsigned int Grid<T>::size() const
{ 
	return(this->rows*this->cols); 
}

#endif

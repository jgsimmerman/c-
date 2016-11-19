/* Homework 1 -- USC CSCI 102 -- Data Structures

Your job is to create a console-driven application to allow a user to keep track of their movie collection (whether it be DVD, Blu-Ray or digital).

You are to allow the user to enter individual movies and information about those movies to build up a database of their personal movie collection.
You are also to allow the user to set up a list of "favorites" that contains a subset of all the movies that are in their movie database (a "favorites" list
is simply a list of movies that have already been entered into the database by the user). Movies can be added or deleted from the favorites list.
For this assignment, you can assume that the user will only have one "favorites" list. Users must be allowed to print out their favorites list to the screen
as well as print out all the songs in the database.

You must use a C++ class to represent a single movie entry. You may use any other C++ classes as you see fit (e.g. a Database class might make sense,
but is not required).

The minimum data for a movie is the following (feel free to add, if you find additional information useful/necessary):

Movie name
Movie director (assume it's just one person's name)
Movie language (e.g. English)
Run Time (length of the movie in minutes)
Year (year the movie came out)
Rating (must a be a valid MPAA Rating: G, PG, PG13, R, NC17)
Subtitled (a bool value that is true if the movie is subtitled, false otherwise)
The following data must be validated when accepting input from the user:

Run Time is measured in minutes and must be a positive integer.
Year must be 1900 or greater.
Rating must be selected from the set of known ratings (G,PG,PG13,R,NC17). You might want to consider using an enum for this.
Subtitled must accept a basic yes/no or true/false entry (your choice of how to phrase the question).
All fields must be entered for every movie.
The data for a particular user will not persist beyond a single run of the application. You don't have to worry about storing movies and
favorites lists to files and reloading them when the user runs the application multiple times. Everything will start from scratch every time
the application is run.

You are NOT allowed to use any classes or algorithms from the C++ Standard Template Library (STL) except for the vector class.
*/

#include <iostream>
using namespace std;


class Movie
{
    private:
        // all fields must be entered for each movie
        string name;
        string director;
        string language;
        int runtime;
        int year; //must be 1900 or greater
        enum rating {G = 1, PG = 2, PG13 = 3, R = 4, NC17 = 5}; //must be from known ratings (G, PG, PG13, R, NC17)... how to use enum?
        bool subtitled; //yes/no question

    public:
        Movie();
        ~Movie();

        string getName();
        void setName(string n);
        string getDirector();
        void setDirector(string d);
        string getLanguage();
        void setLanguage(string l);
        int getRuntime();
        void setRuntime(int r);
        int getYear();
        void setYear(int y);
        //enum getRating();
        //void setRating();
        bool getSubtitled();
        void setSubtitled(bool s);


};

Movie::Movie(){}
Movie::~Movie(){}

string Movie::getName()
    {return name;}
void Movie::setName(string n)
    {name=n;}
string Movie::getDirector()
    {return director;}
void Movie::setDirector(string d)
    {director=d;}
string Movie::getLanguage()
    {return language;}
void Movie::setLanguage(string l)
    {language=l;}
int Movie::getRuntime()
    {return runtime;}
void Movie::setRuntime(int r)
    {runtime=r;}
int Movie::getYear()
    {return year;}
void Movie::setYear(int y)
    {year=y;}
/*Enum Rating classes here

*/
bool Movie::getSubtitled()
    {return subtitled;}
void Movie::setSubtitled(bool s)
    {subtitled=s;}

int main()
{



    return 0;
}

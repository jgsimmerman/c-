/* Lab 2 USC CSCI 102 -- Data Structures

    You are to write a program that will help the USC basketball team sell discounted tickets.
    There are five different types of tickets each with a different cost:

        (A) Students without an activity card	$2.00
        (B) Faculty and staff	$3.00
        (C) USC alumni	$5.00
        (D) UCLA students and alumni	$20.00
        (E) Everyone else	$10.00

    Part I:
        Prompt the ticket seller for the type of ticket - A through E - and the number of that type of ticket to be purchased.
        You are to keep track of the total number of each kind of ticket sold. Use a single vector to track these values (i.e. vector[0]
        stores the total number of student tickets, vector[1] stores the total number of faculty/staff tickets, etc.).
        DO NOT use 5 different variables, just use one vector that is 5 elements long.

        When the user enters a letter 'S', it means they want to stop selling tickets and halt the program.
        You are then to display the total number of each type of ticket sold and the total value of those tickets, each on a line.
        The last line of output is the total money collected by this ticket seller.

        Your output should be a nicely aligned table.

        Your code should be robust enough to handle most reasonable bad values (e.g. a ticket quantity of -1 or "asdf"). (cin.fail()?)

    Part II: E.C.
        Read from a File
    Part III: E.C.
        Write to a file
*/

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main()
{
    vector<int>ticketTotals;
    char type;
    int quant;
    while(type != 's' || type != 'S')
    {
        cout<<left<<setw(39)<<"[A] Students Without an Activity Card"<<"  $2.00\n";
        cout<<setw(39)<<"[B] Faculty an Staff"<<"  $3.00\n";
        cout<<setw(39)<<"[C] USC Alumni"<<"  $5.00\n";
        cout<<setw(39)<<"[D] UCLA Students and Alumni"<<"  $20.00\n";
        cout<<setw(39)<<"[E] Everyone Else"<<"  $10.00\n";
        cout<<"\n\t Type 's' to quit...\n";

        cout<<"\nWhat type of ticket did you sell? ";
        cin>>type; //how to use cin.fail()???????
        if(type == 's' || type == 'S') break;
        cout<<"\nHow many of this type of ticket did you sell? ";
        cin>>quant;

        switch(type)
        {   case 'A':
            case 'a':   for(int i=0; i<quant; i++) ticketTotals.push_back(0);
                        break;
            case 'B':
            case 'b':   for(int i=0; i<quant; i++) ticketTotals.push_back(1);
                        break;
            case 'C':
            case 'c':   for(int i=0; i<quant; i++) ticketTotals.push_back(2);
                        break;
            case 'D':
            case 'd':   for(int i=0; i<quant; i++) ticketTotals.push_back(3);
                        break;
            case 'E':
            case 'e':   for(int i=0; i<quant; i++) ticketTotals.push_back(4);
                        break;
            default:    cout<<"Unidentified Entry.\n";
        }

    }

    vector<int>::iterator i;

    int a=0, b=0, c=0, d=0, e=0;

    for (i=ticketTotals.begin(); i != ticketTotals.end(); i++)
    {   if(*i == 0) a++;
        else if(*i == 1) b++;
        else if(*i == 2) c++;
        else if(*i == 3) d++;
        else e++;
    }

        cout<<left<<setw(39)<<"Type of Ticket"<<setw(10)<<"Quantity"<<setw(8)<<"Total"<<endl;
        cout<<setw(39)<<" Students Without an Activity Card"<<setw(10)<<a<<setw(8)<<left<<"$"<<a*2<<".00"<<endl;
        cout<<setw(39)<<" Faculty an Staff"<<setw(10)<<b<<setw(8)<<"$"<<b*3<<".00"<<endl;
        cout<<setw(39)<<" USC Alumni"<<setw(10)<<c<<setw(8)<<"$"<<c*5<<".00"<<endl;
        cout<<setw(39)<<" UCLA Students and Alumni"<<setw(10)<<d<<setw(8)<<"$"<<d*20<<".00"<<endl;
        cout<<setw(39)<<" Everyone Else"<<setw(10)<<e<<setw(8)<<"$"<<e*10<<".00"<<endl;



    return 0;
}

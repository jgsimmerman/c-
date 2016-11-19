#include <iostream>
#include <vector>
#include <iomanip>
#include "TicketOrder.h"

using namespace std;

int main()
{

	vector<TicketOrder> orders;
	int quantity;
	char type;

      do{TicketOrder instance;
	cout<<left<<setw(39)<<"[A] Students Without an Activity Card "<<" $2.00\n";
	cout<<setw(39)<<"[B] Faculty and Staff"<<" $3.00\n";
	cout<<setw(39)<<"[C] USC Alumni "<<" $5.00\n";
	cout<<setw(39)<<"[D] UCLA Students and Alumni "<<" $20.00\n";
	cout<<setw(39)<<"[E] Everyone Else "<<" $10.00\n";

	cout<<"\n\tType 's' to quit...\n";

	do{
		cout<<"\nWhat type of ticket did you sell? ";
		cin>>type;
		if(type=='s' || type=='S') break;
	  }
	while(type!='A' && type!='a' && type!='B' && type!='b' && type !='C'
	    && type!='c' && type!='D' && type!='d' && type!='E' && type!='e');
    if(type == 's' || type == 'S') continue;
	do
	{	while(true)
		{
			cout<<"\nHow many of this type of ticket did you sell? ";
			cin>>quantity;

			//check if input failed
			if(cin.fail())
			{
				cerr<<"Bad input. Please try again." <<endl;
				cin.clear();//clear the failure flag
				cin.ignore(1000,'\n'); //wipe 'cin'
				continue;
			}
			else {break;}
		 }
	 }
	while(quantity<0);

	instance.setQuantity(quantity);
	instance.setType(type);


	orders.push_back(instance);
      }
     while(type!='s' && type!='S');

	int a=0, b=0, c=0, d=0, e=0;


	vector<TicketOrder>::iterator i;

	int x=0;
	//TicketOrder to = orders.at(x);

	for (i=orders.begin(); i!=orders.end(); i++)
	{
		TicketOrder to = orders.at(x);
		int q=to.getQuantity();

		if(to.getType() == 'a') for(int y=0; y<q; y++) a++;
		else if(to.getType()=='b') for(int y=0; y<q; y++) b++;
		else if(to.getType()=='c') for(int y=0; y<q; y++) c++;
		else if(to.getType()=='d') for(int y=0; y<q; y++) d++;
		else for(int y=0; y<q; y++) e++;
		x++;
	}

		cout<<left<<setw(39)<<"Type of Ticket"<<setw(10)<<"Quantity"<<setw(8)<<"Total"<<endl;
        cout<<setw(39)<<" Students Without an Activity Card"<<setw(10)<<a<<setw(8)<<left<<"$"<<a*2<<".00"<<endl;
        cout<<setw(39)<<" Faculty an Staff"<<setw(10)<<b<<setw(8)<<"$"<<b*3<<".00"<<endl;
        cout<<setw(39)<<" USC Alumni"<<setw(10)<<c<<setw(8)<<"$"<<c*5<<".00"<<endl;
        cout<<setw(39)<<" UCLA Students and Alumni"<<setw(10)<<d<<setw(8)<<"$"<<d*20<<".00"<<endl;
        cout<<setw(39)<<" Everyone Else"<<setw(10)<<e<<setw(8)<<"$"<<e*10<<".00"<<endl;

	return 0;
}

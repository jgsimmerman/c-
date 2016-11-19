#include <iostream>
#include <iomanip>
#include <vector>
#include "TicketOrder.h"

using namespace std;

TicketOrder::TicketOrder()
{
	this->type = 0;
	this->quantity = 0;
}

TicketOrder::TicketOrder(int q, char t)
{
	this->type=t;
	this->quantity=q;
}

char TicketOrder::getType()
{
	return this->type;
}

void TicketOrder::setType(char t)
{
	if(t == 'A' || t == 'a' || t=='B' || t=='b' || t=='C' || t=='c'
	   || t=='D' || t=='d' || t=='E' || t == 'e')
	{
		this->type=t;
	}
}

int TicketOrder::getQuantity()
{
	return this->quantity;
}

void TicketOrder::setQuantity(int q)
{
	if(q>0) {quantity=q;}

}



TicketOrder::~TicketOrder(){}


Mon Sep 27 19:14:15 EDT 2010



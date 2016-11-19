#ifndef TICKETORDER_H_
#define TICKETORDER_H_

class TicketOrder
{
	private:
		int quantity;
		char type;
	public:
		TicketOrder();
		TicketOrder(int q, char t); 

		int getQuantity();
		void setQuantity(int q);
		char getType();
		void setType(char t);


		~TicketOrder();	


};

#endif

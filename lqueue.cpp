//implement of lqueue
//file:lqueue.cpp
#include "lqueue.h"
#include<cstdlib>
lqueue::lqueue(int qs):qsize(qs)
{
	rear=front=nullptr;
	items=0;
}
bool lqueue::isempty() const
{
	if(items==0) return true;
	else return false;
}
bool lqueue::isfull() const
{
	if(items==qsize) return true;
	else return false;
}
bool lqueue::enqueue(const Item & it)
{
	if(isfull()) 
	    return false;
	else
	{
		Node * add = new Node;
		add->item = it;
		add->next = nullptr;
		items++;
		if(front==nullptr)
		    front = add;
		else 
		    rear->next = add;
		rear = add;
		return true;
	}
}
bool lqueue::dequeue(Item & it)
{
	if(front==nullptr)
	    return false;
	it = front ->item;
	items--;
	Node * temp =front;
	front = front->next;
	delete temp;
	if(items==0)
	    rear = nullptr;
	return true;
}
lqueue::~lqueue()
{
	Node * temp;
	while(front!=nullptr)
	{
	    
		temp = front;
		front = front -> next;
		delete temp;
	}
}
void Customer::set(long when)
{
	arrive = when;
	processtime = std::rand() % 3 +1;
}


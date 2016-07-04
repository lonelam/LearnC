//lqueue.h
#ifndef LQUEUE_H_
#define LQUEUE_H_

class Customer
{
private:
long arrive; // arrival time for customer
int processtime; // processing time for customer
public:
Customer() { arrive = processtime = 0; }
void set(long when);
long when() const { return arrive; }
int ptime() const { return processtime; }
};
typedef Customer Item;

class lqueue
{
	enum{QUEUE_SIZE =10
	};
	private:
		struct Node{
			Item item;
			Node * next;
		};
		Node * front;
		Node * rear;
		int items;
		const int qsize;		
	public:
		lqueue(const lqueue & lq):qsize(0) {}
		lqueue(int qs);
		~lqueue();
		lqueue & operator=(lqueue & lq) {return *this;}
		bool isempty() const;
		bool isfull() const;
		int qcount() const {return items;}
		bool enqueue(const Item & it);
		bool dequeue(Item & it);
		
};
#endif

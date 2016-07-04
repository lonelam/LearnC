//FILE:lock.h
//CLASS PROVIDED:lock
//CONSTRUCTOR for the lock class:
//	lock()
//	Postcondition:the lock has been set to 0,0,0
//MEMBER FUNCTION:
////			lock(int x,int y,int z);
//Precondition:0<=x,y,z<=39
//Postcondition:the lock has been set to x,y,z
//			void set(const int new_x,const int new_y,const int new_z);
//Precondition:0<=x,y,z<=39
//Postcondition:the lock has been set to x,y,z
//			void rotate(const bool ifclockwise,const int movelen);
//precondition: movelen was positive
//Postcondition:
//			void set_locked();
//			bool try_unlock();
#ifndef MAIN_LAI_LOCK
#define MAIN_LAI_LOCK
namespace main_lai_lock
{
	class lock
	{
		public:
			lock();
			lock(int init_x,int init_y,int init_z);
			bool set(const int new_x,const int new_y,const int new_z);
			void rotate(const bool ifclockwise,const int movelen);
			void set_locked();
			bool try_unlock();
			const bool if_locked(){return lock_con;};
			const int getnum(){return topnum;};
		private:
			int topnum;
			int x,y,z;//password
			bool lastdirection;
			int laststay;//last stay when the direction reversed
			int step;//the condition of each circle lock
			bool lock_con;// locked or unlocked
			int scale;
	};
}
#endif

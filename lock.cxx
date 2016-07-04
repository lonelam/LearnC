//FILE:lock.cxx
//IMPLEMENT OF CLASS LOCK
#include<cassert>
#include"lock.h"
//using main_lai_lock::lock;
namespace main_lai_lock
{
	using namespace main_lai_lock;
	lock::lock(int init_x,int init_y,int init_z)
	{
		scale=40;
		assert(init_x>=0&&init_x<scale&&init_y>=0&&init_y<scale&&init_z>=0&&init_z<scale);
		x=init_x;
		y=init_y;
		z=init_z;
		lastdirection=false;
		step=0;
		topnum=0;
	}
	lock::lock()
	{
		x=0;
		y=0;
		z=0;
		lastdirection=false;
		step=0;
		topnum=0;
		scale=40;
	}
	void lock::rotate(const bool ifclockwise,const int movelen)
	{
		assert(movelen>0);
		if(ifclockwise&&(topnum+movelen>laststay+scale)) step=0;
		if(step==0)
		{
			if(ifclockwise)
			{
				topnum+=movelen;
				if (topnum>(laststay+scale))
				{
					topnum=topnum%scale;
					if(topnum==x)
					{
						step=1;
						laststay=topnum;
					}
				}
				topnum=topnum%scale;
			}
			else
			{
				topnum-=movelen;
				topnum=topnum%scale;
				if(topnum<0)
				{
					topnum+=scale;
				}
				laststay=topnum;
			}
		}
		else 
		if(step==1)
		{
			if(!ifclockwise)
			{
				topnum-=movelen;
				topnum=topnum%scale;
				if(topnum<0)
				{
					topnum+=scale;
				}
				if(topnum==y)
				{
					step=2;
					laststay=topnum;
				}
			}
			else
			{
				topnum+=movelen;
				if(topnum>=scale)
				{
					topnum-=scale;
					laststay-=scale;
				}
			}
		}
		else
		if(step==2)
		{
			if(ifclockwise)
			{
				topnum+=movelen;
				topnum=topnum%scale;
			}
			else
			{
				topnum-=movelen;
				topnum=topnum%scale;
				if(topnum<0)
				{
					topnum+=scale;
				}
				if(topnum!=y) step=1;
				else laststay=topnum;
			}
		}
		lastdirection=ifclockwise;
	}
	bool lock::set(const int new_x,const int new_y,const int new_z)
	{
//		assert(new_x>=0&&new_x<scale&&new_y>=0&&new_y<scale&&new_z>=0&&new_z<scale);
		if (lock_con) return false;
		else
		{
			x=new_x;
			y=new_y;
			z=new_z;
			return true;
		}
	}
	bool lock::try_unlock()
	{
		if(step==2&&topnum==z) 
		{
			lock_con=false;
			step=0;
			laststay=topnum;
			return true;
		}
		else
		{
			step=0;
			laststay=topnum;
			return false;
		}
	}
	void lock::set_locked()
	{
		if(!lock_con)
		{
			lock_con=true;
			step=0;
			laststay=topnum;
		}
	}
}

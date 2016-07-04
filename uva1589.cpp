#include<vector>
#include<iostream>
#include<utility>
using namespace std;
int main()
{
	int n,g_x,g_y;
	while(cin>>n>>g_x>>g_y &&n!=0)
	{
		bool board[12][11] = {false};
		bool checked[12][11] = {false};
		char piece;
		int p_x,p_y;
		vector< pair<int,int>> G,R,H,C;
		for(int i=0;i<n;i++)
		{
			cin>>piece>>p_x>>p_y;
			
			board[p_x][p_y] = true;
			
			if(piece == 'G')
			{
				G.push_back({p_x,p_y});
			}
			else if(piece == 'R')
			{
				R.push_back({p_x,p_y});
			}
			else if(piece == 'H')
			{
				H.push_back({p_x,p_y});
			}
			else
			{
				C.push_back({p_x,p_y});
			}
		}
		for(auto x : G)
		{
			for(int i=x.first-1;i>0;i--)
			{
				if(board[i][x.second])
				{
					checked[i][x.second] = true;
					break;
				}
				checked[i][x.second] = true;
			}
		}
		for(auto x: R)
		{
			for(int i=x.first-1;i>0;i--)
			{
				if(board[i][x.second])
				{
					checked[i][x.second] = true;
					break;
				}
				checked[i][x.second] = true;
			}
			for(int i=x.first+1;i<11;i++)
			{
				if(board[i][x.second])
				{
					checked[i][x.second] = true;
					break;
				}
				checked[i][x.second] = true;
			}
			for(int j = x.second+1;j<10;j++)
			{
				if(board[x.first][j])
				{
					checked[x.first][j] = true;
					break;
				}
				checked[x.first][j] = true;
			}
			for(int j=x.second-1;j>0;j--)
			{
				if(board[x.first][j])
				{
					checked[x.first][j] = true;
					break;
				}
				checked[x.first][j] = true;
			}
			
			
		}
		for(auto x : C)
		{
			bool jumped = false;
			for(int i=x.first-1;i>0;i--)
			{
				if(board[i][x.second])
				{
					if(!jumped)
					{
						jumped = true;
						continue;
					}
					else
					{
						checked[i][x.second] = true;
						break;
					}
				}
				if(jumped)
				{
					checked[i][x.second] = true;
				}
			}
			jumped = false;
			for(int i=x.first+1;i<11;i++)
			{
				if(board[i][x.second])
				{
					if(!jumped)
					{
						jumped = true;
						continue;
					}
					else
					{
						checked[i][x.second] = true;
						break;
					}
				}
				if(jumped)
				checked[i][x.second] = true;
			}
			jumped = false;
			for(int j = x.second+1;j<10;j++)
			{
				if(board[x.first][j])
				{
					if(!jumped)
					{
						jumped = true;
						continue;
					}
					else
					{
						checked[x.first][j] = true;
						break;
					}
				}
				if(jumped)
				checked[x.first][j] = true;
			}
			jumped = false;
			for(int j=x.second-1;j>0;j--)
			{
				if(board[x.first][j])
				{
					if(!jumped)
					{
						jumped = true;
						continue;
					}
					else
					{
						checked[x.first][j] = true;
						break;
					}
				}
				if(jumped)
				checked[x.first][j] = true;
			}
		}
		for(auto x : H)
		{
			if(x.first>2 && !board[x.first -1][x.second])
			{
				if(x.second>1)
				    checked[x.first-2][x.second-1] = true;
				if(x.second<9)
				    checked[x.first-2][x.second+1] =true;
			}
			if(x.first<9 && !board[x.first+ 1][x.second])
			{
				if(x.second>1)
				{
					checked[x.first+2][x.second-1] = true;
				}
				if(x.second < 9)
				{
					checked[x.first+2][x.second+1] = true;
				}
			}
			if(x.second>2 && !board[x.first][x.second-1])
			{
				if(x.first>1)
				    checked[x.first-1][x.second - 2] = true;
				if(x.first<10)
				{
					checked[x.first+1][x.second-2] = true;
				}
			}
			if(x.second < 9 && !board[x.first][x.second+1])
		    {
		    	if(x.first>1)
		    	{
		    		checked[x.first-1][x.second+2] = true;
				}
				if(x.first<10)
				    checked[x.first+1][x.second+2] = true;
			}
		}
		if((g_x==1||checked[g_x-1][g_y])&&(g_x==3||checked[g_x+1][g_y])
		    &&(g_y==4||checked[g_x][g_y-1])&&(g_y==6||checked[g_x][g_y+1]))
		    cout<<"YES"<<endl;
		    else
		    cout<<"NO"<<endl;
	//	cout<<" "<<checked[g_x-1][g_y]<<" "<<checked[g_x+1][g_y]<<" "<<checked[g_x][g_y-1]<<" "<<checked[g_x][g_y+1]<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

bool Place(int board[][10], int i, int j, int n)
{
	for(int k=0;k<i;k++)
	{
		if(board[k][j]==1)
			return false;
	}
	
	int x=i;
	int y=j;
	
	while(x>=0 && y>=0)
	{
		if(board[x][y]==1)
			return false;
		x--;
		y--;
	}
	
	x=i;
	y=j;
	
	while(x>=0 && y<n)
	{
		if(board[x][y]==1)
			return false;
		x--;
		y++;
	}
	
	return true;
}

bool solve(int board[][10],int i, int n)
{
	if(i==n){
		//print board
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j] == 1)
					cout<<"Q";
				else
					cout<<"_";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}
		for(int j=0;j<n;j++)
		{
			if(Place(board,i,j,n)){
				board[i][j] = 1;
				bool nextPlacement = solve(board,i+1,n);
				if(nextPlacement)
					return true;
			}
			board[i][j] = 0;
		}
	
	return false;
}
int main()
{
	int n;
	cin>>n;
	int board[10][10]={0};
	solve(board,0,n);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int solve(int arr[50][50], bool visited[50][50],int n, int m, int i, int j)
{
    if(i==n && j==m)
        return 1;
    if(i>n || j>m)
        return 0;
    if(i<0 || j<0)
        return 0;
    if(arr[i][j]==0)
        return 0;
    if(visited[i][j])
        return 0;
    
    visited[i][j]=true;

    int dx[]={-1,0,1,0};
    int dy[]={0,-1,0,1};

    for(int k=0;k<4;k++)
    {
        if(solve(arr,visited,m,n,i+dx[k],j+dy[k]))
        	return true;
	}
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[50][50];
    bool v[50][50];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            v[i][j]=false;
        }
    }

    if(solve(arr,v,n-1,m-1,0,0)) cout<<"Yes";
	else cout<<"No";
}
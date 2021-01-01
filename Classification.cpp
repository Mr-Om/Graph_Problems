#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph
{
public:
        map<T,int> inTime;
        map<T,int> exitTime;
        map<T,list<T>> adjList;

    bool isAncestor(T x, T y)
    {
        return (inTime[x]<inTime[y] && exitTime[x]>exitTime[y]);
    }

    bool isForwardEdge(T x, T y)
    {
        return isAncestor(x,y);
    }

    bool isBackEdge(T x, T y)
    {
        return isAncestor(y,x);
    }

    bool isCrossEdge(T x, T y)
    {
        if(isForwardEdge(x,y) || isBackEdge(y,x))
            return false;
        return true;
    }
    
    void addEdge(T src, T dest)
    {
        adjList[src].push_back(dest);
    }

    void dfsHelper(map<T,bool> &visited, T src, int &timer)
    {
        
        visited[src]=true;
        inTime[src]=timer++;
        for(auto neighbour:adjList[src])
        {
            if(!visited[neighbour])
            {
                dfsHelper(visited,neighbour,timer);
            }
        }
        exitTime[src]=timer++;
    }

    void dfs(T src)
    {
        int timer=0;
        map<T,bool> visited;
        dfsHelper(visited, src, timer);
    }

};

int main()
{
    Graph<string> g;
    g.addEdge("A","B");
    g.addEdge("B","E");
    g.addEdge("E","C");
    g.addEdge("C","D");
    g.addEdge("D","E");

    g.dfs("A");

    for(auto i:g.adjList)
    {
        for(auto j:g.adjList[i.first])
        {
            if(g.isForwardEdge(i.first,j))
                cout<<i.first<<"->"<<j<<" Forward Edge"<<endl;
            else if(g.isBackEdge(i.first,j))
                cout<<i.first<<"->"<<j<<" Back Edge"<<endl;
            else if(g.isCrossEdge(i.first,j))
                cout<<i.first<<"->"<<j<<" Cross Edge"<<endl;
        }
    }

}
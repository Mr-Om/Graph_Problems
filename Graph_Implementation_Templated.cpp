#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<T> > adjList;
public:
    Graph()
    {

    }   

    void addEdge(T u, T v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {
        for(auto i:adjList)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

    void bfs(T source)
    {
        queue<T> q;
        map<T,bool> visited;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();

            for(auto neighbours : adjList[node])
            {
                if(!visited[neighbours])
                {
                    visited[neighbours]=true;
                    q.push(neighbours);
                }
            }
        }
    }

    void bfs2(T src)
    {
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;
        for(auto i:adjList)
        {
            dist[i.first]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        parent[src]=src;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto neighbours:adjList[node])
            {
                if(dist[neighbours] == INT_MAX)
                {
                    q.push(neighbours);
                    dist[neighbours] = dist[node]+1;
                    parent[neighbours]=node;
                }
            }
        }

        for(auto it:adjList)
        {
            cout<<it.first<<" distance-> "<<dist[it.first]<<endl;
        }
    }

    void dfsHelper(T node, map<T,bool> &visited)
    {
        visited[node]=true;
        cout<<node<<" ";
        for(auto neighbour:adjList[node])
        {
            if(!visited[neighbour])
                dfsHelper(neighbour,visited);
        }
    }

    void dfs(T src)
    {
        map<T,bool> visited;
        dfsHelper(src,visited);
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,4);

    //g.bfs2(0);
    g.dfs(0);
}
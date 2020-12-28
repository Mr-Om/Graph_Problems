#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
 public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[v];
    }
   
    void addEdge(int v, int u, int bidir=true)
    {
        l[v].push_back(u);
        if(bidir)
        l[u].push_back(v);
    }

    void printGraph()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(auto j:l[i])
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.printGraph();

}
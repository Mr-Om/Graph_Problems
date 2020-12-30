#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<T> > adjList;
public:
    
    void addEdge(T u, T v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }

    vector<int> getallVertex()
    {
        vector<int> v;
        for(auto i:adjList)
        {
            v.push_back(i.first);
        }
        return v;
    }
    /*vector<pair<int, int> >getallEdges()
    {
        vector<pair<int, int>> v;
        for(auto i:adjList)
        {
            for(auto j:i.second)
            {
                v.push_back({i.first,j});
            }
        }
        return v;
    }*/
};

class DisjointSet{
    public:
    struct Node
    {
        int data;
        Node* parent;
        int rank;
    };

    map<int,Node*> mp;

    void makeSet(int data)
    {
        Node* node = new Node();
        node->data = data;
        node->parent = node;
        node->rank = 0;
        mp[data]=node;
    }

    void Union(int data1, int data2)
    {
        //cout<<"in find "<<data1<<" "<<data2<<endl;
        Node* node1 = mp[data1];
        Node* node2 = mp[data2];

        Node* parent1 = findSet(node1);
        Node* parent2 = findSet(node2);


        if(parent1->data == parent2->data)
            return;
        
        if(parent1->rank >= parent2->rank)
        {
            parent1->rank = (parent1->rank == parent2->rank)?parent1->rank + 1: parent1->rank;
            parent2->parent = parent1->parent;
        }
        else
        {
            parent1->parent = parent2;
        }

    }

    int findSet(int data)
    {
        return (findSet(mp[data])->data);
    }

    Node* findSet(Node* node)
    {
        //cout<<"in "<<node->data<<endl;
        Node* parent = node->parent;
        if(parent == node)
        {
            return parent;
        }
        node->parent = findSet(node->parent);
        return (node->parent);
    }
};

int main()
{
    bool cycle = false;
    Graph<int> g;
    vector<pair<int,int> > edges;
    g.addEdge(0, 1);
    edges.push_back({0, 1});
    g.addEdge(1, 2);
    edges.push_back({1, 2});
    g.addEdge(0, 3);
    edges.push_back({0, 3});
    g.addEdge(3, 4);
    edges.push_back({3, 4});
    g.addEdge(4, 5);
    edges.push_back({4, 5});
    g.addEdge(5, 1);
    edges.push_back({5, 1});
    vector<int> vertex = g.getallVertex();
    //vector<pair<int,int> > edges = g.getallEdges();
    /*for(auto i:edges)
    {
        cout<<i.first<<" "<<i.second;
        cout<<endl;
    }*/
    DisjointSet ds;
    for(auto i:vertex)
    {
        ds.makeSet(i);
    }

    for(auto edge : edges)
    {
        
        int parent1 = ds.findSet(edge.first);
        
        int parent2 = ds.findSet(edge.second);
        
        if(parent1 == parent2)
        {
            cycle=true;
            break;
        }
        ds.Union(edge.first,edge.second);
    }

    if(cycle)
        cout<<"true";
    else
    {
        cout<<"false";
    }
    
}
/*

This algorithm running time is O(EV) but sometimes it is very important to find the negative cycle in the graph, if it's DAG than we can just apply relaxing also for each vertex
accoring to the order of topological sort obtained vertex

In this algorithm we need to take care about negative cycle, In order to detect negative cycle, we perform this algorithm (#vertex-1) times and after performing the algorithm this number of times
all the nodes must have got their shortest path from the source node, but if we process this algo of balancing each edge then if we found any more shortest path, then we might get to know which of them
are in directly negative cycle of attached to some negative cycle so they may get affected by that cycle */


#include<iostream>
#include<bitset>
#include<vector>
#include<limits.h>
using namespace std;
int *dist,siz;

/* Initializing the distance array to maximum possible value */

void initialize(int n)
{
  dist=new int[n];
  int siz=n;
  for(int i=0;i<siz;i++)
  {
    dist[i]=INT_MAX;
  }
}

/*Algorithm for bellman ford */

void bellmanford(int n,vector<pair<int,int>> *graph)
{
  dist[0]=0;
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n;j++)
    {
      for(int k=0;k<graph[j].size();k++)
      {
        if(dist[j]+graph[j][k].second<dist[graph[j][k].first])
        {
          dist[graph[j][k].first]=dist[j]+graph[j][k].second;
        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {
int n,e,s,d,w;
cout<<"Enter the number of vertex\t";
cin>>n;
initialize(n);
vector<pair<int,int>> *graph=new vector<pair<int,int>>[n];
cout<<"Enter the number of edges\t";
cin>>e;
for(int i=0;i<e;i++)
{
  cin>>s>>d>>w;
  graph[s].push_back(make_pair(d,w));
}
bellmanford(n,graph);
for(int i=0;i<n;i++)
{
  cout<<dist[i]<<" ";
}
  return 0;
}

/*

This algorithm has a very high running time complexity, it mostly applicable only if the graph has some hundred nodes, it's running time complexity is O(V^3) so it's very rare to use
but the best thing is it can find all pairs shortest path, i.e. from each node to other node. it can also detect negative cycles

In case of flyod algorithm the optimal way to represent graph is two dimensional adjency matrix
*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int>*dist;
int siz;

void initialize(vector<int>*graph,int n)
{
  siz=n;
  dist=new vector<int>[n];
  for(int i=0;i<n;i++)
  {
    dist[i].resize(n);
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i==j)continue;
      else if(graph[i][j]==0)dist[i][j]=INT_MAX/2;
      else dist[i][j]=graph[i][j];
    }
  }
}

void allpairsshortestpath()
{
  for(int k=0;k<siz;k++)
  {
    for(int i=0;i<siz;i++)
    {
      for(int j=0;j<siz;j++)
      {
        if(k==i||j==k||i==j)continue;
        if(dist[i][k]+dist[k][j]<dist[i][j])
        {
          dist[i][j]=dist[i][k]+dist[k][j];
        }
      }
    }
  }
}

int main()
{
  int n,e,s,d,w;
  cout<<"Enter the number of nodes\t";
  cin>>n;
  vector<int> *graph=new vector<int>[n];
  for(int i=0;i<n;i++)
  {
    graph[i].resize(n);
  }
  cout<<"Enter the number of edges\t";
  cin>>e;
  for(int i=0;i<e;i++)
  {
    cin>>s>>d>>w;
    graph[s][d]=w;
  }
  initialize(graph,n);
  allpairsshortestpath();
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<dist[i][j]<<"\t";
    }
    cout<<endl;
  }
  //cout<<1e30;
  return 0;
}

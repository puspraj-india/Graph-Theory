//Note that dijkstra algorithm only works with those graphs which didn't contain -ve weight, so it's an important condition

#include<iostream>
#include<queue>
#include<climits>
#include<bitset>
using namespace std;
//bitset<100> visited;
int *dist,siz;

//function to initialize the distance array

void initialize(int n)
{
  siz=n;
  dist=new int[n];
  for(int i=0;i<n;i++)
  {
    dist[i]=INT_MAX;
  }
}

//Function to calculate shortest path from a source node to all the nodes

void shortestpath(int s,int siz,vector<pair<int,int>> *graph)
{
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  dist[s]=0;
  pq.push(make_pair(0,s));
  pair<int,int> p;
  while(!pq.empty())
  {
    p=pq.top();
    for(int j=0;j<graph[p.second].size();j++)
    {
      if(dist[graph[p.second][j].first]>graph[p.second][j].second+p.first)
      {
        dist[graph[p.second][j].first]=graph[p.second][j].second+p.first;
        pq.push(make_pair(dist[graph[p.second][j].first],graph[p.second][j].first));
      }
    }
    pq.pop();
  }
}


int main(int argc, char const *argv[]) {
  int n,e,s,d,w;
  cout<<"Enter the number of nodes\t";
  cin>>n;
  cout<<"Enter the number of edges\t";
  cin>>e;
  initialize(n);
  vector<pair<int,int>> *graph=new vector<pair<int,int>>[n];
  for(int i=0;i<e;i++)
  {
    cin>>s>>d>>w;
    graph[s].push_back(make_pair(d,w));
  }
  cout<<endl;
  shortestpath(0,n,graph);
  for(int i=0;i<n;i++)
  {
    cout<<dist[i]<<" ";
  }
  return 0;
}

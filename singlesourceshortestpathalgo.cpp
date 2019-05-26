/*

In graph theory single source shortest path have different formula based on different types of graph for example this solution is for DAG or directed Acyclic Graph
in this case find any topological order of graph and then choose any start point and relax all the neighbour node of all the nodes until all the nodes are visited
it's kind of greedy approach and it is the fastest which we can achieve in graph

Remember don't forgot to initilize the array created i.e. top
*/

#include<iostream>
#include<vector>
#include<climits>
//#include<pair>
#include<bitset>
using namespace std;

bitset<100> visited1;
//bitset<100>visited2;
int *top,*dist,siz;

//Function to initialize the size of top, top is basically an array which will store the topological order of the graph
void initialize(int n)
{
top=new int[n];
dist=new int[n];
for(int i=0;i<n;i++)
{
  dist[i]=INT_MAX;
}
siz=n-1;
}

//Function to compute topological order
void topsort(int n,vector<pair<int,int>> *graph)
{
  if(!visited1[n])
  {
    visited1[n]=true;
    for(int i=0;i<graph[n].size();i++)
    {
      topsort(graph[n][i].first,graph);
    }
    top[siz--]=n;
  }
}

//function to calculate single source shortest path, it's just a traversing of top sort values and relaxing the neighbour nodes, if the updated value is less than current value

void sssp(int s_index,int siz,vector<pair<int,int>>*graph)
{
  dist[top[s_index]]=0;
  int val;
  for(int i=s_index;i<siz;i++)
  {
    val=top[i];
    for(int j=0;j<graph[val].size();j++)
    {
      if(dist[graph[val][j].first]>dist[val]+graph[val][j].second)
      {
        dist[graph[val][j].first]=dist[val]+graph[val][j].second;
      }
    }
  }
}


int main()
{
int n,e,s,d,w;
cout<<"Enter the number of nodes\t";
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
for(int i=0;i<n;i++)
{
  if(!visited1[i])
  {
    topsort(i,graph);
  }
}
for(int i=0;i<n;i++)
{
  cout<<top[i]<<" ";
}
cout<<endl;
sssp(0,n,graph);
for(int i=0;i<n;i++)
{
  cout<<dist[i]<<" ";
}
return 0;
}

#include<iostream>
#include<vector>
using namespace std;
vector<bool> visited(100);
vector<int> components(100);

void dfs(vector<int> *graph,int node,int count)
{
  if(!visited[node])
  {
    visited[node]=true;
    components[node]=count;
    int sz=graph[node].size();
    for(int i=0;i<sz;i++)
    {
      dfs(graph,graph[node][i],count);
    }
  }
}

void findComponents(vector<int> *graph,int n)
{
  int count=0;
  for(int i=0;i<n;i++)
  {
    if(!visited[i])
    {
      dfs(graph,i,count);
      count++;
    }
  }
}

int main()
{
int n,e,s,d;
cout<<"Enter the number of nodes";
cin>>n;
vector<int> *graph=new vector<int>[n];
cout<<"Enter the number of edges\t";
cin>>e;
for(int i=0;i<e;i++)
{
  cin>>s>>d;
  graph[s].push_back(d);
}
findComponents(graph,n);
for(int i=0;i<n;i++)
{
  cout<<components[i]<<" ";
}
}

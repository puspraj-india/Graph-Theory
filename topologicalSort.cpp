#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
bitset<100> visited;
int *top;
int siz;
void initialize(int n)
{
  siz=n-1;
  top=new int[n];
}
void topsort(vector<int> *graph,int n)
{
  if(!visited[n])
  {
    visited[n]=true;
    for(int i=0;i<graph[n].size();i++)
    {
      topsort(graph,graph[n][i]);
      //top[siz--]=visited[n][i];
    }
    top[siz--]=n;
  }
}


int main()
{
  int n,e,s,d;
  cout<<"Enter the number of nodes";
  cin>>n;
  initialize(n);
  vector<int> *graph =new vector<int>[n];
  cout<<"Enter the number of edges\t";
  cin>>e;
  for(int i=0;i<e;i++)
  {
    cin>>s>>d;
    graph[s].push_back(d);
  }
  topsort(graph,0);
  for(int i=0;i<n;i++)
  {
    cout<<top[i]<<" ";
  }
}

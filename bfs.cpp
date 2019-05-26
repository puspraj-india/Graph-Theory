#include<iostream>
#include<vector>
#include<bitset>
#include<queue>
using namespace std;

bitset<100> visited;

void bfs(vector<int> *graph,int n)
{
  queue<int> q;
  q.push(n);
  cout<<n<<" ";
  visited[n]=1;
  while(!q.empty())
  {
    int temp=q.front();
    for(int i=0;i<graph[temp].size();i++)
      {
        if(!visited[graph[temp][i]])
        {
          q.push(graph[temp][i]);
          cout<<graph[temp][i]<<" ";
          visited[graph[temp][i]]=1;
        }
      }
      q.pop();
    }
}

int main()
{
  int n,e,s,d;
  cout<<"Enter the number of nodes in graph\t";
  cin>>n;
  vector<int> *graph=new vector<int>[n];
  cout<<"Enter the number of edges in a graph\t";
  cin>>e;
  for(int i=0;i<e;i++)
  {
    cin>>s>>d;
    graph[s].push_back(d);
  }
  bfs(graph,0);
  return 0;
}

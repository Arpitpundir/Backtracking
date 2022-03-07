#include<bits/stdc++.h>
using namespace std;
int visited[1001][1001];
bool ratInmaze(char maze[1001][1001],vector<vector<int> > sol,int i,int j,int n,int m)
{
  if(i==n && j==m)
  {
    sol[i][j]=1;
    for(int x=0;x<=n;x++)
    {
      for(int y=0;y<=m;y++)
      {
        cout<<sol[x][y]<<" ";
      }
      cout<<endl;
    }
    return true;
  }
  if(visited[i][j])
  {
    return false;
  }
  sol[i][j]=1;
  visited[i][j]=1;
  if(j+1<=m && !visited[i][j+1])
  {
    bool rightSuccess=ratInmaze(maze,sol,i,j+1,n,m);
    if(rightSuccess==true)
    {
      return true;
    }
  }
  if(i+1<=n && !visited[i+1][j])
  {
    bool downSuccess=ratInmaze(maze,sol,i+1,j,n,m);
    if(downSuccess==true)
    {
      return true;
    }
  }
  if(j-1>=0 && !visited[i][j-1])
  {
    bool leftSuccess=ratInmaze(maze,sol,i,j-1,n,m);
    if(leftSuccess==true)
    {
      return true;
    }
  }
  if(i-1<=n && !visited[i-1][j])
  {
    bool upSuccess=ratInmaze(maze,sol,i-1,j,n,m);
    if(upSuccess==true)
    {
      return true;
    }
  }
  return false;
}
int main() 
{
  int n,m;
  cin>>n>>m;
  char maze[1001][1001];
  vector<vector<int> > sol;
  sol.resize(n);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>maze[i][j];
      if(maze[i][j]=='X')
      visited[i][j]=1;
    sol[i].push_back(0);
    }
  }
  n=n-1;
  m=m-1;
  bool ans=ratInmaze(maze,sol,0,0,n,m);
  if(ans==0)
  {
    cout<<"NO PATH FOUND";
  }
  return 0;
}
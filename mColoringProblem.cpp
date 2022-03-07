#include<bits/stdc++.h>
using namespace std;
bool isValid(unordered_map<int,vector<int> > &g,vector<int> colours, int node,int col){
  int l=g[node].size();
  for(int i=0;i<l;i++){
    if(colours[g[node][i]]==col){
      return false;
    }
  }
  return true;
}

bool colorGraph(unordered_map<int,vector<int> >g,int totColours, int N,int node,vector<int> &colours){
  if(node==N){
    return true;
  }
  for(int i=1;i<=totColours;i++){
    if(isValid(g,colours,node,i)){
      colours[node]=i;
      if(colorGraph(g,totColours,N,node+1,colours)){
        return true;
      }
      colours[node]=0;
    }
  }
  return false;
}

int main(){
  unordered_map<int,vector<int> > g;
  int n;
  cin>>n;
  int e;
  cin>>e;
  for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int totColours;
  cin>>totColours;
  vector<int> colours;
  colours.resize(n,0);
  cout<<colorGraph(g,totColours,n,0,colours);
  for(int i=0;i<n;i++)
  cout<<colours[i]<<" ";
}
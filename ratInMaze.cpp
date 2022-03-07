#include<bits/stdc++.h>
using namespace std;

void printPath(int i, int j, vector<pair<int, int> > path, vector<vector<int> > mat){
  int n = mat.size();
  int m = mat[i].size();
  //cout<<i<<" "<<j<<endl;

  if(i < 0||j < 0||i >= n||j >= n||mat[i][j] == 0){
    return;
  }
  //for(int i = 0;i < path.size();i++){
    //cout<<path[i].first<<","<<path[i].second<<" ";
  //}
  //cout<<endl;
  if(i == n-1&&j == m-1){
    //cout<<"Apath"<<endl;
    path.push_back(make_pair(i, j));
    int l = path.size();
    for(int i = 0;i < l;i++){
      cout<<path[i].first<<" "<<path[i].second<<endl;
    }
    return;
  }
  path.push_back(make_pair(i, j));
  printPath(i+1, j, path, mat);
  printPath(i, j+1, path, mat);
}

int main(){
  int n, m;
  cin>>n>>m;
  vector<vector<int> > mat(n);

  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      int temp;
      cin>>temp;
      mat[i].push_back(temp);
    }
  }
  vector<pair<int, int> > path;
  printPath(0, 0, path, mat);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;

int checkValid(int row, int col, vector<int> rows, vector<int> cols)
{
  int n = rows.size();  
  int tempRow = row, tempCol = col;
  if(cols[tempCol]){
    return 0;
  }
  
  while (tempRow >= 0 && tempCol >= 0){
    if (ans[tempRow][tempCol]){
      return 0;
    }
    tempRow--, tempCol--;
  }

  tempRow = row, tempCol = col;
  while (tempRow >= 0 && tempCol < n){
    if (ans[tempRow][tempCol]){
      return 0;
    }
    tempRow--, tempCol++;
  }
  return 1;
}

bool nQueens(int ind, vector<int> row, vector<int> col){
  int n = row.size();
  if (ind >= n)
  {
    return true;
  }
  for (int i = 0; i < n; i++){
    if(checkValid(ind, i, row, col)){
      row[ind] = 1;
      col[i] = 1;
      ans[ind][i] = 1;
      if(nQueens(ind+1, row, col)){
        return true;
      }
      row[ind] = 0;
      col[i] = 0;
      ans[ind][i] = 0;
    }
  }
  return false;
}

int main(){
  int n;
  cin >> n;
  ans.resize(n);
  for(int i = 0;i < n;i++){
    ans[i].resize(n);
  }
  vector<int> row(n, 0), col(n, 0);
  nQueens(0, row, col);
  for (int i = 0; i < n; i++){
    for(int j = 0;j < n;j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}
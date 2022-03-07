#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > mat;
bool canPlace(int num, int row, int col){
  int n = mat[0].size();
  int gridRow = row/3, gridCol = col/3;
  gridRow*=3, gridCol*=3;

  //cout<<"1"<<" "<<gridRow<<" "<<gridCol<<endl;

  for(int i = gridRow;i < gridRow+3;i++){
    for(int j = gridCol;j < gridCol+3;j++){
      if(mat[i][j] == num){
        return false;
      }
    }
  }
  for(int i = 0;i < n;i++){
    if(mat[row][i] == num){
      return false;
    }
  }
  for(int i = 0;i < n;i++){
    if(mat[i][col] == num){
      return false;
    }
  }
  return true;
}

bool solveSudoku(int row, int col){
  int n = mat[0].size();
  if(row >= n)
  return true;
  if(col >= 9){
    return solveSudoku(row+1, 0);
  }
  if(mat[row][col] != 0){
    return solveSudoku(row, col+1);
  }
  for(int i = 1;i <= 9;i++){
    if(canPlace(i, row, col)){
      //cout<<"can"<<" "<<i<<" "<<row<<" "<<col<<endl;
      mat[row][col] = i;
      if(solveSudoku(row, col+1)){
        return true;
      }
      mat[row][col] = 0;
    }
  }
  return false;
}

int main(){
  mat = 
 {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
  {5, 2, 0, 0, 0, 0, 0, 0, 0},  
  {0, 8, 7, 0, 0, 0, 0, 3, 1},  
  {0, 0, 3, 0, 1, 0, 0, 8, 0},  
  {9, 0, 0, 8, 6, 3, 0, 0, 5},  
  {0, 5, 0, 0, 9, 0, 6, 0, 0},  
  {1, 3, 0, 0, 0, 0, 2, 5, 0},  
  {0, 0, 0, 0, 0, 0, 0, 7, 4},  
  {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 
  solveSudoku(0, 0);

  for(int i = 0;i < 9;i++){
    cout<<endl;
    for(int j = 0;j < 9;j++){
      cout<<mat[i][j]<<" ";
    }
  }
}
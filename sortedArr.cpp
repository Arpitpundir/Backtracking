#include<bits/stdc++.h>
using namespace std;
bool isSorted(int ind, vector<int> mat){
  int n = mat.size();
  if(ind == n-1){
    return true;
  }
  if(mat[ind]<=mat[ind+1]){
    return isSorted(ind+1, mat);
  }else{
    cout<<ind<<endl;
    return false;
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> mat;
  for(int i = 0;i < n;i++){
    int temp;
    cin>>temp;
    mat.push_back(temp);
  }
  cout<<mat.size()<<endl;
  if(isSorted(0, mat)){
    cout<<"true"<<endl;
  }else{
    cout<<"false"<<endl;
  }
}
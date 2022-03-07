#include<bits/stdc++.h>
using namespace std;

vector<int> allInd(vector<int> arr, vector<int> ans, int m, int ind){
  if(ind == arr.size()){
    return ans;
  }
  if(arr[ind] == m){
    ans.push_back(ind);
  }
  return allInd(arr, ans, m, ind+1);
}

int main(){
  int n;
  cin>>n;
  vector<int> arr;
  for(int i = 0;i < n;i++){
    int temp;
    cin>>temp;
    arr.push_back(temp);
  }
  int m;
  cin>>m;
  vector<int> temp;
  vector<int> ans = allInd(arr, temp, m, 0);

  for(int i = 0;i < ans.size();i++){
    cout<<ans[i]<<endl;
  }
}
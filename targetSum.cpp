#include<bits/stdc++.h>
using namespace std;

void printCombn(vector<int> arr, int ind, vector<int> ans, int sum, int target){
  if(ind == arr.size()){
    if(sum == target){
      for(int i = 0;i < ans.size();i++){
        cout<<ans[i]<<" ";
      }
      cout<<endl;
    }
    return;
  }
  int tempSum = sum+arr[ind];
  vector<int> tempAns = ans;
  tempAns.push_back(arr[ind]);
  printCombn(arr, ind+1, tempAns, tempSum, target);
  printCombn(arr, ind+1, ans, sum, target);
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
  int target;
  cin>>target;
  vector<int> ans;
  set<int> s( arr.begin(), arr.end() );
  arr.assign( s.begin(), s.end() );
  printCombn(arr, 0, ans, 0, target);
}
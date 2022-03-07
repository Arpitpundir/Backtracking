#include<bits/stdc++.h>
using namespace std;

bool subSetSum(vector<int> arr, int ind, int sum, int empty){
  if(ind == arr.size()){
    //cout<<sum<<endl;
    if(sum == 0 && empty){
      return true;
    }
    return false;
  }
  bool res1 = subSetSum(arr, ind+1, sum+arr[ind], 1);
  bool res2 = subSetSum(arr, ind+1, sum, empty);
  return res1 || res2;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i = 0;i < n;i++){
      int temp;
      cin>>temp;
      arr.push_back(temp);
    }
    if(subSetSum(arr, 0, 0)){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}
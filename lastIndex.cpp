//Every call of recursion should return something.

#include<bits/stdc++.h>
using namespace std;
int findIndex(vector<long int> arr, int ind, int found, long int num){
  //cout<<ind<<" "<<found<<" "<<num<<endl;
    if(arr[ind] == num)
      found = ind;
    if(ind == arr.size()-1){
      return found;
    }
  return findIndex(arr, ind+1, found, num);
}
int main(){
  int n;
  cin>>n;
  vector<long int> arr;
  for(int i = 0;i < n;i++){
    int temp;
    cin>>temp;
    arr.push_back(temp);
  }
  long int num;
  cin>>num;
  cout<<findIndex(arr, 0, -1, num)<<endl;
}
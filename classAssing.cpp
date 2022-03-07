#include<bits/stdc++.h>
using namespace std;

int uniqueInt(int n, char a, char b, string num){
  if(n == 0){
    //cout<<num<<endl;
    return 1;
  }
  if(num.size() > 0 && num[num.size()-1] == b){
    num.push_back(a);
    return uniqueInt(n-1, a, b, num);
  }
  string temp = num;
  num.push_back(a);
  temp.push_back(b);
  return uniqueInt(n-1, a, b, num)+uniqueInt(n-1, a, b, temp);
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<uniqueInt(n, 'a', 'b', "")<<endl;
  }
  return 0;
}
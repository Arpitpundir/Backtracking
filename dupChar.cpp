#include<bits/stdc++.h>
using namespace std;

string insertChar(string str, int ind){
  //cout<<str<<" "<<ind<<endl;
  if(str[ind] == str[ind+1]){
    str.insert(ind+1, "*");
    //cout<<"*"<<" "<<str<<endl;
  }
  if(ind == str.size()-2){
    return str;
  }
  return insertChar(str, ind+1);
}

int main(){
  string str;
  cin>>str;
  cout<<insertChar(str, 0)<<endl;
}
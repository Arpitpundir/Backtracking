#include<bits/stdc++.h>
using namespace std;

string replacePi(string str, int ind){
  string temp = str.substr(ind, 2);
  if(temp == "pi"){
    str.replace(ind, 2, "3.14");
    ind+=2;
  }
  if(ind+2 == str.size()){
    return str;
  }//if ind + 2 == n then there is only one char remaining to check which we dont have to.
  return replacePi(str, ind+1);
}

int main(){
  int t;
  cin>>t;
  while(t--){
    string str;
    cin>>str;
    cout<<replacePi(str, 0)<<endl;
  }
}
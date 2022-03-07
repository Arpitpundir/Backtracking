#include<bits/stdc++.h>
using namespace std;

string removeDup(string str, int ind){
  //cout<<str<<endl;
  if(str[ind] == str[ind+1]){
    str.erase(str.begin()+ind);
    return removeDup(str, ind);
    //be carefull when using a mutated object
    
    //cout<<"rem"<<" "<<str<<endl;
  }
  if(ind == str.size()-1){
    return str;
  }
  return removeDup(str, ind+1);
}

int main(){
  string str;
  cin>>str;
  cout<<removeDup(str, 0)<<endl;
}
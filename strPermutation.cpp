#include<bits/stdc++.h>
using namespace std;

string swap(string str, int i, int j){
  char temp = str[i];
  str[i] = str[j];
  str[j] = temp;
  return str;
}

void permute(string str, int ind){
  if(ind == str.size()){
    cout<<str<<endl;
    return;
  }
  for(int i = ind;i < str.size(); i++){
    str = swap(str, ind, i);
    permute(str, ind+1);
    str = swap(str, ind, i);
  }
}

int main(){
  string str;
  cin>>str;
  permute(str, 0);
}
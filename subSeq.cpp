#include<bits/stdc++.h>
using namespace std;

int subSeq(string str, string str2, int ind){
  if(ind == str.size()){
    cout<< str2<<" ";
    return 1;
  }
  string str3 = str2, str4= str2;
  str3.push_back(str[ind]);
  return subSeq(str, str3, ind+1)+subSeq(str, str4, ind+1);
}

int main(){
  string str;
  cin>>str;
  int tot = subSeq(str, "", 0);
  cout<<endl<<tot<<endl;
}
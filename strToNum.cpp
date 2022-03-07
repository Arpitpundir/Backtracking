#include<bits/stdc++.h>
using namespace std;

int strToNum(string str, int ind, long int num){
  //cout<<num<<endl;
  num += (str[ind] - '0')*pow(10, str.size() - ind-1);
  if(ind == 0){
    return num;
  }
  return strToNum(str, ind-1, num);
}
int main(){
  string str;
  cin>>str;
  cout<<strToNum(str, str.size()-1, 0);
}
#include<bits/stdc++.h>
using namespace std;

void printPara(int pos, int n, int open, int close, string str){
  //cout<<str<<" "<<open<<" "<<close<<" "<<pos<<endl;
  if(close == n){
    cout<<str<<endl;
    return;
  }
  if(open > close){
    str.push_back(')');
    printPara(pos+1, n, open, close+1, str);
    str.pop_back();
  }
  if(open < n){
    str.push_back('(');
    printPara(pos+1, n, open+1, close, str);
  }
}

int main(){
  int n;
  cin>>n;
  printPara(1, n, 1, 0, "(");
}
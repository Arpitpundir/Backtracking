#include<bits/stdc++.h>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void printCodes(string str, string str2, int ind){
  if(ind >= str.size()){
    
    cout<<str2<<endl;
    return;
  }
  int tableInd = str[ind] - '0';
  for(int i = 0;i < table[tableInd].size();i++){
    string temp = str2;
    temp.push_back(table[tableInd][i]);
    printCodes(str, temp, ind+1);
  }
  return;
}

int main(){
  string str;
  cin>>str;
  printCodes(str, "", 0);
}
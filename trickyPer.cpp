#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void trickyPer(string str, int ind){
  if(ind == str.size() - 1){
    ans.push_back(str);
    return;
  }
  trickyPer(str, ind+1);
  int l = str.size();
  for(int i = ind;i < l;i++){
    if(str[i] != str[ind]){
      swap(str[ind], str[i]);
      trickyPer(str, ind+1);
      swap(str[ind], str[i]);
    }
  }
}

int main(){
  string str;
  cin>>str;
  vector<char> arr;
  int l = str.size();
  for(int i = 0;i < l;i++){
    arr.push_back(str[i]);
  }
  sort(arr.begin(), arr.end());
  str.clear();
  for(int i = 0;i < l;i++){
    str.push_back(arr[i]);
  }

  trickyPer(str, 0);

  sort(ans.begin(), ans.end());
  l = ans.size();
  set<string> s(ans.begin(), ans.end());
  ans.assign(s.begin(), s.end());
  l = ans.size();
  for(int i = 0;i < l;i++){
    cout<<ans[i]<<endl;
  }
}
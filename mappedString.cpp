#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
bool compare(string str1 , string str2){
  return str1 < str2;
}

void mapString(string str, string str2, int ind){
  if(ind == str.size()){
    ans.push_back(str2);
    //cout<<"str2"<<" "<<str2<<" "<<ind<<" "<<"end"<<endl;
    return;
  }else if(ind == str.size()-1){
    str2.push_back(65 + (str[ind] - '0')-1);
    //cout<<"str2"<<" "<<str2<<" "<<ind<<" "<<"end"<<endl;
    ans.push_back(str2);
    return;
  }
  int hind = (str[ind] - '0')*10+(str[ind+1]-'0');
  string str3 = str2;
  if(hind <= 26){
    str3.push_back(65+hind-1);
    //cout<<"str3"<<" "<<str3<<" "<<ind<<endl;
    mapString(str, str3, ind+2);
  }
  str2.push_back(65 + (str[ind] - '0')-1);
  //cout<<"str3"<<" "<<str3<<" "<<ind<<endl;
  mapString(str, str2, ind+1);
}

int main(){
  string str;
  cin>>str;
  mapString(str, "", 0);
  sort(ans.begin(), ans.end(), compare);
  int n = ans.size();
  for(int i = 0;i < n;i++){
    cout<<ans[i]<<endl;
  }
}
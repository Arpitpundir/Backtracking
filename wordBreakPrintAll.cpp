#include<bits/stdc++.h>
using namespace std;
void wordBreakPrint(string str, int ind, string curr, vector<string> &ans,unordered_map<string,bool> mp){
  int n=str.size();
  cout<<ind<<" "<<n<<endl;
  if(ind==n){
    ans.push_back(curr);
    return;
  }
  for(int i=ind;i<n;i++){
    string temp=str.substr(ind,i-ind+1);
   // cout<<temp<<" "<<mp[temp]<<" "<<i<<endl;
    if(mp.find(temp)!=mp.end())
    wordBreakPrint(str,i+1,curr+" "+temp,ans,mp);
  }
}
int main(){
  vector<string> words={"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
  unordered_map<string,bool> mp;
  int l=words.size();
  for(int i=0;i<l;i++){
   // cout<<words[i]<<endl;
    mp[words[i]]=1;
  }
  string str;
  cin>>str;
  vector<string> ans;
  wordBreakPrint(str,0,"",ans,mp);
  l=ans.size();
  for(int i=0;i<l;i++){
    cout<<ans[i]<<endl;
  }
}
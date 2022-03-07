#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
bool mycompare(string a,string b){
  return a < b;
}

void permute(string str,int i,string cpy){
    if(str[i]=='\0'&& str < cpy){
        ans.push_back(str);
        return ;
    }
    for(int j=i;str[j]!='\0';j++){
      swap(str[i],str[j]);
            permute(str,i+1,cpy);
            swap(str[i],str[j]);
        // line 21 here I am facing issues
    }
}

int main(){
    string str;
    cin>>str;
    string cpy = str;
    permute(str,0,cpy);
  sort(ans.begin(), ans.end(), mycompare);
  for(int i = 0;i < ans.size();i++){
    if(ans[i] != str)
    cout<<ans[i]<<endl;
  }
    return 0;
}
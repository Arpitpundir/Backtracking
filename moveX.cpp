#include<bits/stdc++.h>
using namespace std;

void moveX(string str, int ind, int count){
  if(ind >= str.size()){
    cout<<str;
    for(int i = 0;i < count;i++){
      cout<<'x';
    }
    return;
  }

  if(str[ind] == 'x'){
    str.erase(ind, 1);
    count++;
    ind--;
  }
  //cases
  //2nd last ind and i erase this ind
  //last ind and i erase this ind 
  moveX(str, ind+1, count);
}
int main(){
  string str;
  cin>>str;
  moveX(str, 0, 0);
}
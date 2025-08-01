#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
char pChange(char p){
  switch(p){
    case 'B': return 'L';
    case 'L': return 'D';
    case 'D': return 'B';
  }
  return 'B';
}
set<deque<char>> s;

int main(){
  int n;
  cin>>n;
  deque<char> v(n*3);
  for(int i=0;i<n*3;++i){
    cin>>v[i];
  }
  int ans=0;
  int left=0,right=n-1;
  char p='B';
  queue<pair<pair<int,char>,deque<char>>> q;
  q.push({{0,'B'},v});
  while(!q.empty()){
    int maxAns=q.front().first.first;
    char currentM=q.front().first.second;
    deque<char> ar=q.front().second;
    q.pop();
    ans=max(maxAns,ans);
    if(ar.size()==0) continue;
    if(ar[0]==currentM){
      
      deque<char> newAr(ar.size());
      for(int i=0;i<ar.size();++i){
        newAr[i]=ar[i];
      }
      newAr.pop_front();
      if(s.find(newAr)==s.end()){
        q.push({{maxAns+1,pChange(currentM)} ,newAr});
        s.insert(newAr);
      }
    }
    if(ar[ar.size()-1]==currentM){
      deque<char> newAr(ar.size());
      for(int i=0;i<ar.size();++i){
        newAr[i]=ar[i];
      }
      newAr.pop_back();
            if(s.find(newAr)==s.end()){
        q.push({{maxAns+1,pChange(currentM)} ,newAr});
        s.insert(newAr);
      }
    }
  }
  cout<<ans;
}
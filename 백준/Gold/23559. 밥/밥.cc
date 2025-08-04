#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
int main(){
  int n,x;
  cin>>n>>x;
  vector<pair<ll,ll>> v(n,pair<ll,ll>());
  for(int i=0;i<n;++i){
    cin>>v[i].first>>v[i].second;
  }
  vector<bool> visited(n,false);
  ll ans=0;
  priority_queue<ll> q;
  for(int i=0;i<n;++i){
    ans+=v[i].second;
    x-=1000;
    q.push(v[i].first-v[i].second);
  }
  while(!q.empty()&&x>=4000){
    ll val=q.top();
    q.pop();
    if(val<=0) break;
    x-=4000;
    ans+=val;
  }
  cout<<ans;
}
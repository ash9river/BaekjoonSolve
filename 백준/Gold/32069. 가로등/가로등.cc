#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#define ll long long
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll l,k,n;
  vector<ll> ans;
  set<ll> s;
  cin>>l>>n>>k;
  vector<ll> v(n,0);
  for(int i=0;i<n;++i) cin>>v[i];
  priority_queue<pair<ll,ll>> q;
  for(int i=0;i<n;++i){
    q.push({0,v[i]});
    s.insert(v[i]);
  }
  while(!q.empty()){
    if(ans.size()==k) break;
    ll val=-q.top().first;
    ll order=q.top().second;
    q.pop();
    ans.push_back(val);
    ll nextLeft=order-1;
    ll nextRight=order+1;
    if(nextLeft>=0&&s.count(nextLeft)==0){
      q.push({-(val+1),nextLeft});
      s.insert(nextLeft);
    }
    if(nextRight<=l&&s.count(nextRight)==0){
      q.push({-(val+1),nextRight});
      s.insert(nextRight);
    }
  }
  for(int i=0;i<ans.size();++i) cout<<ans[i]<<"\n";
}
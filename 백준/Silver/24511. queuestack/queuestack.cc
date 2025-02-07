#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    vector<int> table(n);
    for(int i=0;i<n;++i){
        cin>>table[i];
    }
    vector<ll> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    ll m;
    cin>>m;
    vector<ll> target(m);
    for(int i=0;i<m;++i){
        cin>>target[i];
    }
    queue<ll> q;
    for(int i=n-1;i>=0;--i){
        if(table[i]==0){
            q.push(v[i]);
        }
    }
    for(int i=0;i<m;++i){
        q.push(target[i]);
    }
    for(int i=0;i<m;++i){
        ll ans=q.front();
        q.pop();
        cout<<ans<<" ";
    }
}
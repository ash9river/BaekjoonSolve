#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<m;++i){
        cin>>b[i];
    }
    sort(b.begin(),b.end());
    ll aWin=0,bWin=0,mu=0;
    for(int i=0;i<n;++i){
        auto lo=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        auto hi=upper_bound(b.begin(),b.end(),a[i])-b.begin();
        ll gae=hi-lo;
        mu+=gae;
        if(lo>0){
            aWin+=lo;
        }
    }
    bWin=m*n-aWin-mu;
    cout<<aWin<<" "<<bWin<<" "<<mu;
}
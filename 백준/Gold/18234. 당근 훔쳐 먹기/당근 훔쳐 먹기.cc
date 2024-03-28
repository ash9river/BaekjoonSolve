#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n,t;
    cin>>n>>t;
    vector<pair<ll,ll>> v(n);
    ll a,b;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        v[i]={b,a}; 
    }
    sort(v.begin(),v.end());
    ll ans=0;
    ll ptr=t-n;

    for(int i=0;i<n;++i){
        ans+=v[i].second+v[i].first*ptr;
        ++ptr;
    }
    cout<<ans;
}
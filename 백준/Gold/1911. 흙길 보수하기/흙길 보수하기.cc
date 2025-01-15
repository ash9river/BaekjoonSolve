#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n,l;
    cin>>n>>l;
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;++i){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    ll ans=0;
    ll lastPanel=-1;
    for(ll i=0;i<n;++i){
        if(lastPanel>=v[i].second) continue;
        if(lastPanel>=v[i].first) v[i].first=lastPanel+1;
        if(v[i].second-v[i].first<=0) continue;

        if((v[i].second-v[i].first)%l!=0){
            lastPanel=v[i].second-1+l-(v[i].second-v[i].first)%l;
            ans+=(v[i].second-v[i].first)/l+1;
        }
        else{
            lastPanel=v[i].second-1;
            ans+=(v[i].second-v[i].first)/l;
        }
    }
    cout<<ans;
}
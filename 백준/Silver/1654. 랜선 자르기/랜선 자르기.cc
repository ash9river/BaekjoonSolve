#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<ll> v(1000000);
int n,k;
bool fn(int a){
    ll gae=0;
    for(int i=0;i<n;++i){
        gae+=v[i]/a;
    }
    if(gae>=k) return true;
    return false;
}
int minParametricSearch(ll lo,ll hi){
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        if(fn(mid)){
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    return hi;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    ll tmpMax=0;
    for(int i=0;i<n;++i){
        cin>>v[i];
        tmpMax=max(tmpMax,v[i]);
    }
    cout<<minParametricSearch(1,tmpMax);
}
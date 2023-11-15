#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n,m;
vector<ll> tree(1000000);
bool fn(ll mid){
    ll sum=0;
    for(int i=0;i<n;++i){
        if(tree[i]>mid) sum+=tree[i]-mid;
    }
    return sum>=m;
}

int parametricSearching(ll lo,ll hi){
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        if(fn(mid)){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return hi;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    ll tmpMax=0;
    for(int i=0;i<n;++i) {
        cin>>tree[i];
        tmpMax=max(tmpMax,tree[i]);
    }
    cout<<parametricSearching(0,tmpMax);
}
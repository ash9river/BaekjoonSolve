#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define MOD 1000000007LL
using namespace std;
ll table[300001];
ll makeTable(ll n){
    ll& ret=table[n];
    if(ret!=0) return ret;
    if(n==0) return ret=1;
    if(n&(1<<0)) return ret=(2*makeTable((n-1)/2)*makeTable((n-1)/2))%MOD;
    return ret=(makeTable(n/2)*makeTable(n/2))%MOD;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            ll p=j-i-1;
            ll val=v[j]-v[i];
            if(p>0) {
                ans+=val*makeTable(p);
                ans=ans%MOD;
            }
            else {
                ans+=val;
                ans=ans%MOD;
            }
        }
    }
    cout<<ans;
}
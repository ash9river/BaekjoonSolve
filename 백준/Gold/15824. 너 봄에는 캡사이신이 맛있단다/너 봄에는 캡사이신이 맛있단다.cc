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
    if(n&(1<<0)) {
        ll tmp=makeTable((n-1)/2);

        return ret=(2*tmp*tmp)%MOD;
    }
    ll tmp=makeTable(n/2);
    return ret=(tmp*tmp)%MOD;
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
    makeTable(n);
    ll ans=0;
    // (v[i]-v[j])*2^x
    // --> v[i]*2^x - v[j]*2^x
    for(int i=0;i<n;++i){
        ll fi=(v[i]*makeTable(i))%MOD;
        ll se=(v[n-1-i]*makeTable(i))%MOD;
        ans=(ans+fi-se+MOD)%MOD;
    }
    cout<<ans;
}
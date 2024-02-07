#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;//25%간초과
ll NUM_MAX=1000000001LL;
vector<bool> prime(NUM_MAX);
deque<ll> table;
void makePrime(){
    prime[0]=prime[1]=false;
    for(ll i=2;i*i<NUM_MAX;++i){
        if(prime[i]){
            for(ll j=i*i;j<NUM_MAX;j+=i){
                prime[j]=false;
            }
        }
    }
}
ll phi(ll n){
    ll ans=1;
    for(ll i=2;i*i<=n;++i){
        ll tmp=0;
        while(n%i==0){
            ++tmp;
            n/=i;
        }
        if(tmp==0) continue;
        ll b=1;
        for(ll j=0;j<tmp-1;++j){
            b*=i;
        }
        b*=(i-1LL);
        if(b!=0) ans*=b;
    }
    if(n>1){
        ans*=(n-1);
    }
    return ans;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    makePrime();
    for(ll i=1;i*i<=n;++i){
        if(n%i==0){
            table.push_back(i);
            if(i*i!=n) table.push_back(n/i);
        }
    }
    ll ans=-1;
    sort(table.begin(),table.end());
    for(int i=0;i<table.size();++i){
        ll tmp=phi(table[i]);
        if(table[i]*tmp==n){
            ans=table[i];
            break;
        }
    }
    cout<<ans;
}
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;
ll NUM_MAX=1000001;
vector<bool> prime(NUM_MAX);
void makePrime(){
    prime[0]=prime[1]=false;
    ll NUM_MAX=1000000000001;
    for(ll i=2;i*i<NUM_MAX;++i){
        if(prime[i]){
            ll NUM_MAX=1000000000001;
            for(ll j=i*i;j<NUM_MAX;j+=i){
                prime[j]=false;
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    makePrime();
    ll ans=1;
    for(ll i=2;i<NUM_MAX;++i){
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
    cout<<ans;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
vector<bool> isPrime;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll a,b;
	cin>>a>>b;
	isPrime.resize(10000001LL,true);
	isPrime[0]=isPrime[1]=false;
	for(ll i=2;i<=10000000LL;++i){
		if(isPrime[i]){
			for(ll j=i*i;j<=10000000LL;j+=i){
				isPrime[j]=false;
			}
		}
	}
	ll ans=0;
	for(ll i=2;i<=min(10000000LL,b);++i){
		if(isPrime[i]){
			for(ll j=i*i;j<=b;j*=i){
				if(j<a) continue;
				++ans;
				if(b/j<i) break;
			}
		}
	}
	cout<<ans;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll f[1000001];
ll mod=1000000007;
ll n,m;
ll modInv(ll a,ll b){
	ll jisu=mod-2;
	while(jisu){
		if(jisu&1LL) a=a*b%mod;
		b=b*b%mod;
		jisu>>=1LL;
	}
	return a;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	f[0]=1;
	for(ll i=1;i<=n;++i) f[i]=f[i-1]*i%mod;
	cout<<modInv(f[n],f[n-m]*f[m]%mod);
}
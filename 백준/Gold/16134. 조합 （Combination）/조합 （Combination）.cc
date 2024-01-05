#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll f[1000001],n,r;
ll mod=1000000007;
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
	cin>>n>>r;
	f[0]=1;
	for(int i=1;i<=n;++i) f[i]=i*f[i-1]%mod;
	cout<<modInv(f[n],f[r]*f[n-r]%mod);
}
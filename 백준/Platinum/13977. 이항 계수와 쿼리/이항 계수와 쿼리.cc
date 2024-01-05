#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll f[4000001],n,k;
ll mod=1000000007;
ll modInv(ll a,ll b){
	ll jisu=mod-2;
	while(jisu){
		if(jisu&1LL) a=a*b%mod;
		b=b*b%mod;
		jisu=jisu>>1LL;
	}
	return a;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	f[0]=1;
	int m;
	cin>>m;
	for(int i=1;i<=4000000;++i) f[i]=f[i-1]*i%mod;
	while(m-->0){
		cin>>n>>k;
		cout<<modInv(f[n],f[k]*f[n-k]%mod)<<"\n";
	}
}
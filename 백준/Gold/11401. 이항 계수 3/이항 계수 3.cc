#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll f[4000001],n,k;
ll p=1000000007;
ll modInv(ll a,ll b){
	ll jisu=p-2;
	for(;jisu;jisu>>=1){
		if(jisu&(ll)1) a=a*b%p; // x*x^((n-1)/2) 이므로 x 하나 떼어냄
		b=b*b%p; // 이후 (p-2)/2 반복
	}
	return a;

}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	f[0]=1;
	for(int i=1;i<=n;++i){
		f[i]=i*f[i-1]%p;
	}
	cout<<modInv(f[n],(f[k]%p*f[n-k]%p)%p);
}
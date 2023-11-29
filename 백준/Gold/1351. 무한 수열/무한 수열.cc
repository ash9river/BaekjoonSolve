#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
map<ll,ll> m;
ll su(ll n,ll p,ll q){
	if(n<=0) return 1;
	if(m.count(n)>0) return m[n];
	return m[n]=su(n/p,p,q)+su(n/q,p,q);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n,p,q;
	cin>>n>>p>>q;
	cout<<su(n,p,q);
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;
vector<vector<ll>> v;
vector<ll> a;
vector<ll> b;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	v.resize(4,vector<ll>(n));
	for(int i=0;i<n;++i){
		for(int j=0;j<4;++j){
			cin>>v[j][i];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			a.push_back(v[0][i]+v[1][j]);
			b.push_back(v[2][i]+v[3][j]);
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll ans=0;
	for(auto it=a.begin();it!=a.end();++it){
		ll val=*it;
		val=-val;
		auto idxA=lower_bound(b.begin(),b.end(),val)-b.begin();
		auto idxB=upper_bound(b.begin(),b.end(),val)-b.begin();
		ll gae=idxB-idxA;
		ans+=gae;
	}
	cout<<ans;
}
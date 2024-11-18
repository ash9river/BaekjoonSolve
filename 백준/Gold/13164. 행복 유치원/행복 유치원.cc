#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	vector<ll> tmp(n-1);
	priority_queue<ll> q;
	for(int i=0;i<n-1;++i){
		tmp[i]=v[i+1]-v[i];
		q.push(-tmp[i]);
	}
	ll gae=n-k,ans=0;
	while(gae>0){
		ll val=-q.top();
		q.pop();
		ans+=val;
		--gae;
	}
	cout<<ans;
}
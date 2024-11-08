#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n,m;
	cin>>n>>m;
	vector<ll> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	} 
	priority_queue<ll> q;
	ll sum=0,ans=0;
	for(int i=0;i<n;++i){
		sum+=v[i];
		q.push(v[i]);
		while(sum>=m){
			ll val=q.top();
			sum-=2*val;
			q.pop();
			++ans;
		}
	}
	cout<<ans;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	priority_queue<ll> q;
	ll a;
	for(int i=0;i<n;++i){
		cin>>a;
		q.push(-a);
	}
	ll tmpMax=-q.top()*n;
	q.pop();
	int gae=n-1;
	while(!q.empty()){
		ll f=-q.top();
		q.pop();
		tmpMax=max(tmpMax,f*gae);
		--gae;
	}
	cout<<tmpMax;
}
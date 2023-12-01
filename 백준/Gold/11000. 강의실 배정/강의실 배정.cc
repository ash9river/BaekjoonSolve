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
	ll a,b;
	ll maxGae=0,gae=0;
	priority_queue<pair<ll,bool>> q;//true먼저
	for(int i=0;i<n;++i){
		cin>>a>>b;//끝나는건 true,시작은 false
		q.push({-a,false});
		q.push({-b,true});
	}
	while(!q.empty()){
		ll f=-q.top().first;
		bool state=q.top().second;
		q.pop();
		if(state) --gae;
		else ++gae;
		maxGae=max(maxGae,gae);
	}
	cout<<maxGae;
}
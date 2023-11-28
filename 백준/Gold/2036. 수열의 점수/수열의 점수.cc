#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<ll> table(n);
	priority_queue<ll> minusQ;
	priority_queue<ll> plusQ;
	ll a;
	ll zeroGae=0;
	for(int i=0;i<n;++i){
		cin>>a;
		if(a>0) plusQ.push(a);
		else if(a<0) minusQ.push(-a);
		else ++zeroGae;
	}
	ll ans=0;
	while(!plusQ.empty()){
		ll tmp=plusQ.top();
		plusQ.pop();
		if(tmp==1){
			ans+=tmp;	
		}
		else if(plusQ.empty()){
			ans+=tmp;
		}
		else{
			ll tmp2=plusQ.top();
			if(tmp2==1){
				ans+=tmp;
				continue;
			}
			plusQ.pop();
			ans+=tmp*tmp2;
		}
	}
	while(!minusQ.empty()){
		ll tmp=-minusQ.top();
		minusQ.pop();
		if(minusQ.empty()){
			if(zeroGae>0){
				continue;
			}else{
				ans+=tmp;
			}
		}
		else{
			ll tmp2=-minusQ.top();
			minusQ.pop();
			ans+=tmp*tmp2;
		}
	}
	cout<<ans;
}
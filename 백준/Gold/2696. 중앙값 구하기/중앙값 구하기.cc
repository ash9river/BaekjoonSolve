#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;//62퍼틀
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t-->0){
		priority_queue<ll> smallQ;
		priority_queue<ll> bigQ;
		int m;
		cin>>m;
		ll val;
		cin>>val;
		queue<ll> ansQ;
		bigQ.push(-val);
		ansQ.push(val);
		for(int i=0;i<m-1;++i){
			cin>>val;
			if(smallQ.size()==bigQ.size()) bigQ.push(-val);
			else smallQ.push(val);
			if(!smallQ.empty()&&!bigQ.empty()){
				ll a=smallQ.top();
				ll b=-bigQ.top();
				if(a>b){
					smallQ.pop();
					bigQ.pop();
					smallQ.push(b);
					bigQ.push(-a);
				}
			}
			if(i&(1<<0)) ansQ.push(-bigQ.top());
		}
		int ptr=0;
		cout<<ansQ.size()<<"\n";
		while(!ansQ.empty()){
			cout<<ansQ.front()<<" ";
			ansQ.pop();
			++ptr;
			if(ptr==10){
				ptr=0;
				cout<<"\n";
			}
		}
		if(ptr!=0) cout<<"\n";
	}
}
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;//93%틀
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll t;
	cin>>t;
	while(t-->0){
		ll k;
		cin>>k;
		char Is;
		ll n;
		map<ll,ll> m;
		priority_queue<ll> maxQ;
		priority_queue<ll> minQ;
		for(ll i=0;i<k;++i){
			cin>>Is>>n;
			if(Is=='I'){
				maxQ.push(n);
				minQ.push(-n);
				if(m.count(n)>0) m[n]=m[n]+1;
				else m[n]=1;
			}
			else{
				if(n==1){
					bool state=false;
					while(!maxQ.empty()&&!state){
						ll maxVal=maxQ.top();
						maxQ.pop();
						ll gae=0;
						if(m.count(maxVal)>0) gae=m[maxVal];
						if(gae>1){
							m[maxVal]=m[maxVal]-1;
							state=true;
						}
						else if(gae==1){
							m.erase(maxVal);
							state=true;
						}
					}
					if(!state){
						maxQ=priority_queue<ll>();
						minQ=priority_queue<ll>();
					}
					
				}else{
					bool state=false;
					while(!minQ.empty()&&!state){
						ll minVal=-minQ.top();
						minQ.pop();
						ll gae=0;
						if(m.count(minVal)>0) gae=m[minVal];
						if(gae>1){
							m[minVal]=m[minVal]-1;
							state=true;
						}
						else if(gae==1){
							m.erase(minVal);
							state=true;
						}
					}
					if(!state){
						maxQ=priority_queue<ll>();
						minQ=priority_queue<ll>();
					}
				}
			}
		}
		bool state=false;
		if(!m.empty()) state=true;
		if(!state){
			cout<<"EMPTY\n";
		}
		else{
			ll maxVal,minVal;
			while(!maxQ.empty()){
				maxVal=maxQ.top();
				maxQ.pop();
				if(m.count(maxVal)>0) break;
			}
			while(!minQ.empty()){
				minVal=-minQ.top();
				minQ.pop();
				if(m.count(minVal)>0) break;
			}
			cout<<maxVal<<" "<<minVal<<"\n";
		}
	}
}
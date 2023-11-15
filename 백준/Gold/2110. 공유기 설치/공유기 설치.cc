#include <iostream>
#include <vector>	
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;//78%틀
vector<ll> v;
int n,c;
bool fn(int mid){
	int gae=1;
	ll target=v[0];
	for(int i=1;i<n;++i){
		if(v[i]-target>=mid){
			++gae;
			target=v[i];
		}
	}
	return gae>=c;
}
int paraSearch(int lo,int hi){
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(fn(mid)){
			lo=mid+1;
		}else{
			hi=mid-1;
		}
	}
	return hi;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>c;
	v.resize(n);
	ll tmpMax=-1;
	for(int i=0;i<n;++i){
		cin>>v[i];
		tmpMax=max(tmpMax,v[i]);
	}
	sort(v.begin(),v.end());
	cout<<paraSearch(1,tmpMax-v[0]);
}
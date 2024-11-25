#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
vector<ll> v;
vector<ll> leftV;
vector<ll> rightV;
vector<ll> leftPartialSum;
vector<ll> rightPartialSum;
vector<ll> picker;
ll n,c,mid;
void leftPick(int toPick){
	if(toPick==0){
		ll tmpSum=0;
		for(ll k:picker) tmpSum+=leftV[k];
		leftPartialSum.push_back(tmpSum);
		return;
	}
	int idx=picker.empty()?0:picker.back()+1;
	for(int i=idx;i<leftV.size();++i){
		picker.push_back(i);
		leftPick(toPick-1);
		picker.pop_back();
	}
}
void rightPick(int toPick){
	if(toPick==0){
		ll tmpSum=0;
		for(ll k:picker) tmpSum+=rightV[k];
		rightPartialSum.push_back(tmpSum);
		return;
	}
	int idx=picker.empty()?0:picker.back()+1;
	for(int i=idx;i<rightV.size();++i){
		picker.push_back(i);
		rightPick(toPick-1);
		picker.pop_back();
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>c;
	v.resize(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	mid=n/2;
	sort(v.begin(),v.end());
	for(int i=0;i<mid;++i){
		leftV.push_back(v[i]);
	}
	for(int i=mid;i<n;++i){
		rightV.push_back(v[i]);
	}
	for(int i=leftV.size();i>0;--i){
		leftPick(i);
	}
	for(int i=rightV.size();i>0;--i){
		rightPick(i);
	}
	sort(rightPartialSum.begin(),rightPartialSum.end());
	ll ans=0;
	for(int i=0;i<leftPartialSum.size();++i){
		ll val=leftPartialSum[i];
		if(val>c) continue;
		++ans;
		ll limitVal=c-val;
		ll leftIdx=lower_bound(rightPartialSum.begin(),rightPartialSum.end(),limitVal)-rightPartialSum.begin();
		ll rightIdx=upper_bound(rightPartialSum.begin(),rightPartialSum.end(),limitVal)-rightPartialSum.begin();
		ans+=rightIdx;
	}
	for(auto it=rightPartialSum.begin();it!=rightPartialSum.end();++it){
		ll val=*it;
		if(val>c) break;
		++ans;
	}
	cout<<ans+1;
}
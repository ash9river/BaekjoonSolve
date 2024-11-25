#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector<ll> v;
vector<ll> leftV;
vector<ll> rightV;
vector<ll> leftPartialSum;
vector<ll> rightPartialSum;
vector<bool> visited;
vector<ll> picker;
ll n,s,mid;
void leftPick(int topick){
	if(topick==0){
		ll tmpSum=0;
		for(int i=0;i<picker.size();++i){
			tmpSum+=leftV[picker[i]];
		}
		leftPartialSum.push_back(tmpSum);
		return;
	}
	int idx=picker.empty()?0:picker.back()+1;
	for(int i=idx;i<leftV.size();++i){
		picker.push_back(i);
		leftPick(topick-1);
		picker.pop_back();
	}
}
void rightPick(int topick){
	if(topick==0){
		ll tmpSum=0;
		for(int i=0;i<picker.size();++i){
			tmpSum+=rightV[picker[i]];
		}
		rightPartialSum.push_back(tmpSum);
		return;
	}
	int idx=picker.empty()?0:picker.back()+1;
	for(int i=idx;i<rightV.size();++i){
		picker.push_back(i);
		rightPick(topick-1);
		picker.pop_back();
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>s;
	mid=n/2;
	v.resize(n);
	visited.resize(n,false);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
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
		ll crnVal=leftPartialSum[i];
		ll target=s-crnVal;
		int leftIdx=lower_bound(rightPartialSum.begin(),rightPartialSum.end(),target)-rightPartialSum.begin();
		int rightIdx=upper_bound(rightPartialSum.begin(),rightPartialSum.end(),target)-rightPartialSum.begin();
		ans+=(rightIdx-leftIdx);
	}
	for(auto it=leftPartialSum.begin();it!=leftPartialSum.end();++it){
		ll val=*it;
		if(val==s) ++ans;
	}
	for(auto it=rightPartialSum.begin();it!=rightPartialSum.end();++it){
		ll val=*it;
		if(val==s) ++ans;
	}
	cout<<ans;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	set<pair<int,int>> s; // val, index
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
		s.insert({-v[i],i});
	}
	int count=0;
	pair<int,int> ans={-1,-1};
	for(int i=n-1;i>=0;--i){
		int val=-s.begin()->first;
		int idx=s.begin()->second;
		if(v[i]!=val){
			++count;
			int tmpVal=v[i];
			s.erase({-v[i],i});
			s.erase({-val,idx});
			swap(v[i],v[idx]);
			s.insert({-tmpVal,idx});
			if(count==k){
				ans={min(v[idx],v[i]),max(v[idx],v[i])};
				break;
			}
		}
		else{
			s.erase({-v[i],i});
		}
	}
	if(ans.first==-1) cout<<-1;
	else{
		cout<<ans.first<<" "<<ans.second;
	}
}
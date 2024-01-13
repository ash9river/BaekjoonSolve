#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;//12%틀
vector<int> v;
deque<int> picker;
int n,s,gae;
void pick(int toPick,int idx){
	if(toPick==0){
		int sum=0;
		for(int k:picker) sum+=k;
		if(sum==s){
			++gae;
		}
		return;
	}
	for(int i=idx;i<n;++i){
		picker.push_back(v[i]);
		pick(toPick-1,i+1);
		picker.pop_back();
	}
}
void init(){
	for(int i=1;i<=n;++i){
		pick(i,0);
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>s;
	v.resize(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	init();
	cout<<gae;
}
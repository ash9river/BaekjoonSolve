#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;
ll numTable[13];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<string> v(n);
	vector<ll> table(26,0);
	for(int i=0;i<13;++i){
		numTable[i]=1;
		for(int j=0;j<i;++j){
			numTable[i]*=10;
		}
	}
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	for(int i=0;i<n;++i){
		for(int j=v[i].size()-1;j>=0;--j){
			table[v[i][j]-'A']+=numTable[v[i].size()-1-j];
		}
	}
	priority_queue<pair<ll,char>> q;
	for(int i=0;i<26;++i){
		if(table[i]!=0){
			q.push({table[i],i+'A'});
		}
	}
	int ptr=9;
	ll sum=0;
	vector<ll> ans;
	vector<char> ansTable;
	while(!q.empty()){
		ll val=q.top().first;
		char key=q.top().second;
		q.pop();
		ans.push_back(val);
		ansTable.push_back(key);
	}
	if(ans.size()==10){
		set<char> s;
		for(int i=0;i<n;++i){
			if(s.find(v[i][0])==s.end()){
				s.insert(v[i][0]);
			}
		}
		for(int i=9;i>=0;--i){
			if(s.find(ansTable[i])==s.end()){
				ans[i]=0;
				break;
			}
		}
		ptr=1;
		for(int i=9;i>=0;--i){
			if(ans[i]==0) continue;
			sum+=ptr*ans[i];
			++ptr;
		}
	}
	else{
		for(int i=0;i<ans.size();++i){
			sum+=ptr*ans[i];
			--ptr;
		}
	}
	cout<<sum;
}
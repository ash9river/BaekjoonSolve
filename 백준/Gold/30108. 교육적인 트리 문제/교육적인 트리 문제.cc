#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int parent[300001];
ll treeValue[300001];
ll cache[300001];
vector<vector<int>> tree;//2진트리라는보장이없음
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	tree.resize(n+1);
	parent[1]=1;
	priority_queue<pair<ll,int>> q;//value,idx
	for(int i=2;i<=n;++i){
		cin>>parent[i];
		tree[parent[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		cin>>treeValue[i];
	}
	cache[1]=treeValue[1];
	for(int i=0;i<tree[1].size();++i){
		q.push({treeValue[tree[1][i]],tree[1][i]});
	}
	int ptr=2;
	while(!q.empty()){
		ll val=q.top().first;
		int idx=q.top().second;
		q.pop();
		cache[ptr]=cache[ptr-1]+val;
		++ptr;
		for(int i=0;i<tree[idx].size();++i){
			q.push({treeValue[tree[idx][i]],tree[idx][i]});
		}
	}
	for(int i=1;i<=n;++i){
		cout<<cache[i]<<"\n";
	}
}
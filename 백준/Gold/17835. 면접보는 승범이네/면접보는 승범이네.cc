#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define ll long long

using namespace std;
vector<vector<pair<ll,ll>>> graph;
ll n,m,k,u,v,c;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	graph.resize(n+1,vector<pair<ll,ll>>());
	for(int i=0;i<m;++i){
		cin>>u>>v>>c;
		graph[v].push_back({c,u});
	}
	for(int i=1;i<=n;++i){
		sort(graph[i].begin(),graph[i].end());
	}
	vector<ll> endPoints(k);
	priority_queue<pair<ll,ll>> q;
	vector<ll> visited(n+1,LLONG_MAX-100001);
	for(int i=0;i<k;++i){
		cin>>endPoints[i];
		q.push({0,endPoints[i]});
		visited[endPoints[i]]=0;
	}
	while(!q.empty()){
		ll crnDis=-q.top().first;
		ll crnPoints=q.top().second;
		q.pop();
		if(crnDis!=visited[crnPoints]){
			continue;
		} 
		for(int i=0;i<graph[crnPoints].size();++i){
			ll nxtDis=graph[crnPoints][i].first+crnDis;
			ll nxtPoints=graph[crnPoints][i].second;
			if(visited[nxtPoints]>nxtDis){
				visited[nxtPoints]=nxtDis;
				q.push({-nxtDis,nxtPoints});
			}
		}
	}
	pair<ll,ll> ans={0,-1};
	for(int i=1;i<=n;++i){
		if(visited[i]==LLONG_MAX-100001) continue;
		if(visited[i]>ans.first){
			ans={visited[i],i};
		}
	}
	cout<<ans.second<<"\n"<<ans.first;

}
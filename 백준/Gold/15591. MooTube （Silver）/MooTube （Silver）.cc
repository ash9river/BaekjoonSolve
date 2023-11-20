#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;//22% TLE
vector<vector<pair<int,int>>> graph;
vector<vector<int>> USADO;
vector<bool> usedBfs;
int n,Q;
int bfs(int now,int ptr){
	if(!usedBfs[now]){
		vector<bool> visited(n+1,false);
		visited[now]=true;
		priority_queue<pair<int,int>> q;//cost, now
		q.push({-1000000001,now});
		while(!q.empty()){
			int usado=-q.top().first;
			int crn=q.top().second;
			q.pop();
			USADO[now][crn]=usado;
			for(int i=0;i<graph[crn].size();++i){
				int nxt=graph[crn][i].second;
				if(visited[nxt]) continue;
				int nxtUsado=min(graph[crn][i].first,usado);
				visited[nxt]=true;
				q.push({-nxtUsado,nxt});
			}
		}
		usedBfs[now]=true;
	}
	int gae=0;
	for(int i=1;i<=n;++i){
		if(i==now) continue;
		if(USADO[now][i]>=ptr) ++gae;
	}
	return gae;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>Q;
	graph.resize(n+1,vector<pair<int,int>>());
	USADO.resize(n+1,vector<int>(n+1,1000000001));
	usedBfs.resize(n+1,false);
	int p,q,r;
	for(int i=0;i<n-1;++i){
		cin>>p>>q>>r;
		graph[p].push_back({r,q});
		graph[q].push_back({r,p});
	}
	for(int i=1;i<=n;++i){
		sort(graph[i].begin(),graph[i].end());
	}
	for(int i=0;i<Q;++i){
		cin>>p>>q;
		cout<<bfs(q,p)<<"\n";
	}
}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;//4%TLE
vector<vector<int>> graph;
int visited[50001];
int n,m;
void bfs(){
	queue<pair<int,int>> q;
	q.push({0,1});//depth,src
	fill(&visited[0],&visited[50001],987654321);
	visited[1]=0;
	while(!q.empty()){
		int depth=q.front().first;
		int now=q.front().second;
		q.pop();
		for(int i=0;i<graph[now].size();++i){
			int nxt=graph[now][i];
			if(visited[nxt]<=depth+1) continue;
			q.push({depth+1,nxt});
			visited[nxt]=depth+1;
		}
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	graph.resize(n+1,vector<int>());
	int a,b;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs();
	int maxDist=0;
	for(int i=1;i<=n;++i){
		maxDist=max(maxDist,visited[i]);
	}
	int ansGae=0;
	for(int i=1;i<=n;++i){
		if(maxDist==visited[i]) ++ansGae;
	}
	for(int i=1;i<=n;++i){
		if(maxDist==visited[i]){
			cout<<i<<" ";
			break;
		}
	}
	cout<<maxDist<<" "<<ansGae;
}
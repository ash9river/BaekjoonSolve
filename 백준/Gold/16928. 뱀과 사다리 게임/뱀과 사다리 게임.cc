#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
vector<vector<int>> graph;
int cache[101];
void bfs(){
	queue<pair<int,int>> q;
	q.push({0,1});
	cache[1]=0;
	while(!q.empty()){
		int cost=q.front().first;
		int now=q.front().second;
		q.pop();
		bool state=true;
		for(int i=0;i<graph[now].size();++i){
			int nxt=graph[now][i];
			if(cache[nxt]>cost){
				cache[nxt]=cost;
				q.push({cost,nxt});
			}
			state=false;
		}
		if(state){
			for(int i=1;i<=6;++i){
				int nxt=now+i;
				if(nxt>100) continue;
				if(cache[nxt]>cost+1){
					cache[nxt]=cost+1;
					q.push({cost+1,nxt});
				}
			}
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	int a,b;
	graph.resize(101,vector<int>());
	for(int i=0;i<n;++i){
		cin>>a>>b;
		graph[a].push_back(b);
	}
	for(int i=0;i<m;++i){
		cin>>a>>b;
		graph[a].push_back(b);
	}
	fill(&cache[0],&cache[101],987654321);
	bfs();
	cout<<cache[100];
}
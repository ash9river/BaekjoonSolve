#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> graph; 
int ans=987654321;
int v,e;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>v>>e;
	graph.resize(v+1,vector<int>(v+1,987654321));
	int a,b,c;
	for(int i=0;i<e;++i){
		cin>>a>>b>>c;
		graph[a][b]=c;
	}
	for(int k=1;k<=v;++k){
		for(int i=1;i<=v;++i){
			for(int j=1;j<=v;++j){
				if(graph[i][k]==987654321||graph[k][j]==987654321) continue;
				graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
			}
		}
	}
	for(int i=1;i<=v;++i){
		ans=min(graph[i][i],ans);
	}
	if(ans==987654321) ans=-1;
	cout<<ans;
}
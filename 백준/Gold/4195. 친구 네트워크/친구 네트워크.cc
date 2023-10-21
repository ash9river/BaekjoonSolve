#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;//5퍼 segfault
int parent[200001];
int rankOfParent[200001];
int findParent(int vertex){
	if(parent[vertex]!=vertex) parent[vertex]=findParent(parent[vertex]);
	return parent[vertex];
}
void unionByRank(int a,int b){
	int parentA=findParent(a);
	int parentB=findParent(b);
	if(parentA!=parentB){
		if(rankOfParent[parentA]<rankOfParent[parentB]){
			swap(parentA,parentB);
		}
		parent[parentB]=parentA;
		rankOfParent[parentA]+=rankOfParent[parentB];
	}
	cout<<max(rankOfParent[parentA],rankOfParent[parentB])<<"\n";
}
void init(){
	for(int i=0;i<=200000;++i){
		parent[i]=i;
		rankOfParent[i]=1;
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t,f;
	cin>>t;
	while(t-->0){
		string a,b;
		cin>>f;
		init();
		map<string,int> m;
		int ptr=0;
		for(int i=0;i<f;++i){
			cin>>a>>b;
			if(m.count(a)==0) m.insert({a,ptr++});
			if(m.count(b)==0) m.insert({b,ptr++});
			int parentA=findParent(m[a]);
			int parentB=findParent(m[b]);
			unionByRank(parentA,parentB);
		}
	}
}
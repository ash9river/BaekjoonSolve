#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1000001];
int parentGae[1000001];
int findParent(int vertex){
	if(parent[vertex]!=vertex) parent[vertex]=findParent(parent[vertex]);
	return parent[vertex];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(&parentGae[0],&parentGae[1000001],1);
	int n;
	cin>>n;
	char p;
	int a,b;
	for(int i=1;i<=1000000;++i) parent[i]=i;
	for(int i=0;i<n;++i){
		cin>>p>>a;
		if(p=='I'){
			cin>>b;
			int parentA=findParent(parent[a]);
			int parentB=findParent(parent[b]);
			if(parentA!=parentB){
				parent[parentA]=parentB;
				parentGae[parentB]+=parentGae[parentA];
			}
		}else{
			int parentA=findParent(parent[a]);
			cout<<parentGae[parentA]<<"\n";
		}
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> parent(1001);
vector<pair<int,pair<int,int>>> graph;
int n,m;
int Find(int vertex){
    if(parent[vertex]!=vertex) parent[vertex]=Find(parent[vertex]);
    return parent[vertex];
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a,b,c;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        parent[i]=i;
    }
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        graph.push_back(make_pair(c,make_pair(a,b)));
    }
    int ans=0;
    sort(graph.begin(),graph.end());
    for(int i=0;i<m;++i){
        int parentA=Find(graph[i].second.first);
        int parentB=Find(graph[i].second.second);
        if(parentA!=parentB){
            parent[parentA]=parentB;
            ans+=graph[i].first;
        }
    }
    cout<<ans;
}
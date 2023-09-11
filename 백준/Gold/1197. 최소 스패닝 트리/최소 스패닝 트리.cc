#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> parent;
vector<pair<int,pair<int,int>>> graph;//{가중치,{정점a,b}}
int v,e;
//Union-Find
int Find(int vertex){
    if(parent[vertex]!=vertex) parent[vertex]=Find(parent[vertex]);
    return parent[vertex];
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>v>>e;
    int a,b,c;
    for(int i=0;i<e;++i){
        cin>>a>>b>>c;
        graph.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(graph.begin(),graph.end());
    parent.resize(v+1);
    for(int i=1;i<=v;++i){
        parent[i]=i;
    }
    int ans=0;
    for(int i=0;i<e;++i){
        int parentA=Find(graph[i].second.first);
        int parentB=Find(graph[i].second.second);
        if(parentA!=parentB){
            parent[parentA]=parentB;
            ans+=graph[i].first;
        }
    }
    cout<<ans;
}
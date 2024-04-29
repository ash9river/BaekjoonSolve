#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[100001];
int n,m;
int findParent(int vertex){
    if(parent[vertex]!=vertex) parent[vertex]=findParent(parent[vertex]);
    return parent[vertex];
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        parent[i]=i;
    }
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        int parentA=findParent(a);
        int parentB=findParent(b);
        if(parentA!=parentB){
            parent[parentA]=parentB;
        }
    }
    vector<int> table(n);
    for(int i=0;i<n;++i){
        cin>>table[i];
    }
    int ans=0;
    for(int i=0;i<table.size()-1;++i){
        int parentA=findParent(table[i]);
        int parentB=findParent(table[i+1]);
        if(parentA!=parentB) ++ans;
    }
    cout<<ans;
}
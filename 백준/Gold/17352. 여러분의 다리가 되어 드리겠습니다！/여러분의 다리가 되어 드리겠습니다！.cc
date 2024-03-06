#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[300001];
int findParent(int vertex){
    if(parent[vertex]!=vertex){
        parent[vertex]=findParent(parent[vertex]);
    }
    return parent[vertex];
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        parent[i]=i;
    }
    int a,b;
    for(int i=0;i<n-2;++i){
        cin>>a>>b;
        int parentA=findParent(parent[a]);
        int parentB=findParent(parent[b]);
        if(parentA!=parentB){
            parent[parentA]=parentB;
        }
    }
    for(int i=1;i<n;++i){
        int parentA=findParent(parent[i]);
        int parentB=findParent(parent[i+1]);
        if(parentA!=parentB){
            cout<<i<<" "<<i+1;
            break;
        }
    }
}
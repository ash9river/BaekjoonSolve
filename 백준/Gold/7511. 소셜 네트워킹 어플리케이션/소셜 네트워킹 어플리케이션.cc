#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1000001];
int rankOfParent[1000001];
int n,k,m;
int findParent(int vertex){
    if(parent[vertex]!=vertex) parent[vertex]=findParent(parent[vertex]);
    return parent[vertex];
}
void unionWithRank(int& a,int& b){
    int parentA=findParent(a);
    int parentB=findParent(b);
    if(parentA!=parentB){
        if(rankOfParent[parentA]<rankOfParent[parentB]){
            swap(parentA,parentB);
        }
        parent[parentB]=parentA;
        if(rankOfParent[parentA]==rankOfParent[parentB]) ++rankOfParent[parentA];
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t,a,b;
    cin>>t;
    for(int i=1;i<=t;++i){
        cin>>n>>k;
        for(int j=0;j<=n;++j){
            parent[j]=j;
            rankOfParent[j]=1;
        }
        for(int j=0;j<k;++j){
            cin>>a>>b;
            unionWithRank(a,b);
        }
        cin>>m;
        cout<<"Scenario "<<i<<":\n";
        for(int j=0;j<m;++j){
            cin>>a>>b;
            int parentA=findParent(parent[a]);
            int parentB=findParent(parent[b]);
            if(parentA!=parentB) cout<<"0\n";
            else cout<<"1\n";
        }
        cout<<"\n";
    }
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> v(n+1,vector<pair<int,int>>());
    // weight, idx
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({-c,b});
        v[b].push_back({-c,a});
    }
    for(int i=1;i<=n;++i){
        sort(v[i].begin(),v[i].end());
    }
    int startNode,endNode;
    cin>>startNode>>endNode;
    priority_queue<pair<int,int>> q;
    // val, cur
    q.push({1000000000,startNode});
    vector<int> visited(n+1,0);
    visited[startNode]=1000000000;
    int ans=-1;
    while(!q.empty()){
        int val=q.top().first;
        int cur=q.top().second;
        q.pop();
        if(cur==endNode){
            ans=val;
            break;
        }
        if(visited[cur]>val) continue;
        for(int i=0;i<v[cur].size();++i){
            int nxtVal=min(-v[cur][i].first,val);
            int nxtNode=v[cur][i].second;
            if(visited[nxtNode]<nxtVal){
                visited[nxtNode]=nxtVal;
                q.push({nxtVal,nxtNode});
            }
        }
    }
    cout<<ans;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t-->0){
        ll n,d,c;
        cin>>n>>d>>c;
        vector<vector<pair<ll,ll>>> graph(n+1,vector<pair<ll,ll>>());
        for(int i=0;i<d;++i){
            ll a,b,s;
            cin>>a>>b>>s;
            graph[b].push_back({a,s});
        }
        priority_queue<pair<ll,ll>> q;
        q.push({0,c});
        pair<ll,ll> ans={0,0};//gae,time
        vector<ll> visited(n+1,987654321);
        visited[c]=0;
        while(!q.empty()){
            ll time=-q.top().first;
            ll idx=q.top().second;
            q.pop();
            for(int i=0;i<graph[idx].size();++i){
                if(graph[idx][i].second+time<visited[graph[idx][i].first]){  
                    visited[graph[idx][i].first]=graph[idx][i].second+time;
                    q.push({-visited[graph[idx][i].first],graph[idx][i].first});
                }
            }
        }
        for(int i=1;i<=n;++i){
            if(visited[i]<987654321){
                ++ans.first;
                ans.second=max(ans.second,visited[i]);
            }
        }
        cout<<ans.first<<" "<<ans.second<<"\n";
    }
}
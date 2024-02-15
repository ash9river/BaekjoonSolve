#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    vector<int> dp(n+1,987654321);
    int start,end;
    cin>>start>>end;
    dp[start-1]=0;
    priority_queue<pair<int,int>> q;
    q.push({0,start-1});
    while(!q.empty()){
        int gae=-q.top().first;
        int idx=q.top().second;
        q.pop();
        if(dp[idx]<gae) continue;
        for(int i=idx+v[idx];i<n;i+=v[idx]){
            if(dp[i]<=gae+1) continue;
            dp[i]=gae+1;
            q.push({-(gae+1),i});
        }
        for(int i=idx-v[idx];i>=0;i-=v[idx]){
            if(dp[i]<=gae+1) continue;
            dp[i]=gae+1;
            q.push({-(gae+1),i});
        }
    }
    if(dp[end-1]==987654321) dp[end-1]=-1;
    cout<<dp[end-1];
}
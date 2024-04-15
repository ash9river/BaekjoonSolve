#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int c,n;
    cin>>c>>n;
    vector<pair<int,int>> v(n); // meong, cost
    for(int i=0;i<n;++i){
        cin>>v[i].second>>v[i].first;
    }
    sort(v.begin(),v.end());
    vector<int> dp(c+120,987654321);
    dp[0]=0;
    for(int i=0;i<n;++i){
        dp[v[i].first]=min(dp[v[i].first],v[i].second);
    }
    for(int i=1;i<=c+100;++i){
        for(int j=0;j<=i;++j){
            dp[i]=min(dp[i],dp[i-j]+dp[j]);
        }
    }
    int ans=dp[c];
    for(int i=c;i<=c+100;++i){
        ans=min(ans,dp[i]);
    }
    cout<<ans;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//59%틀
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(k+1,200));
    dp[0][0]=0;
    for(int i=1;i<=n;++i){
        int cafe=v[i-1];
        for(int j=0;j<cafe&&j<k;++j){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=cafe;j<=k;++j){
            dp[i][j]=min(dp[i-1][j],dp[i-1][j-cafe]+1);
        }
    }
    int ans=200;
    for(int i=1;i<=n;++i){
        ans=min(ans,dp[i][k]);
    }
    if(ans==200) ans=-1;
    if(k==0) ans=0;
    cout<<ans;
}
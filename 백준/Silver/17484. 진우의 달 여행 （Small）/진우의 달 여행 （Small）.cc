#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m,vector<int>(3,987654321)));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<1;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<3;++k){
                dp[i][j][k]=0;
            }
        }
    }
    for(int j=0;j<m;++j){
        for(int k=0;k<3;++k){
            dp[1][j][k]=v[0][j];
        }
    }
    for(int i=2;i<=n;++i){
        // j=0
        // 0 left 1 down 2 right
        dp[i][0][0]=v[i-1][0]+min(dp[i-1][1][1],dp[i-1][1][2]);
        dp[i][0][1]=v[i-1][0]+dp[i-1][0][0];
        for(int j=1;j<m-1;++j){
            dp[i][j][0]=v[i-1][j]+min(dp[i-1][j+1][1],dp[i-1][j+1][2]);
            dp[i][j][1]=v[i-1][j]+min(dp[i-1][j][0],dp[i-1][j][2]);
            dp[i][j][2]=v[i-1][j]+min(dp[i-1][j-1][0],dp[i-1][j-1][1]);
        }
        //j=m
        dp[i][m-1][1]=v[i-1][m-1]+dp[i-1][m-1][2];
        dp[i][m-1][2]=v[i-1][m-1]+min(dp[i-1][m-2][0],dp[i-1][m-2][1]);
    }
    int ans=987654321;
    for(int i=0;i<m;++i){
        for(int j=0;j<3;++j){
            ans=min(ans,dp[n][i][j]);
        }
    }
    cout<<ans;
}
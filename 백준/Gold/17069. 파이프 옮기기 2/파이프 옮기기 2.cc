#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<vector<ll>> v(n,vector<ll>(n));
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(3,0)));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>v[i][j];
        }
    }
    dp[0][1][0]=1;
    for(int i=2;i<n;++i){
        if(v[0][i]==0){
            dp[0][i][0]=1;
        }
        else break;
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<n;++j){
            if(v[i][j]==0){
                dp[i][j][0]+=dp[i][j-1][0]+dp[i][j-1][1];
                dp[i][j][2]+=dp[i-1][j][2]+dp[i-1][j][1];
                if(v[i-1][j]==0&&v[i][j-1]==0){
                    dp[i][j][1]+=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
                }
            }
        }
    }
    ll ans=dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2];
    cout<<ans;
}
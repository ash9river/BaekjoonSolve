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
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(101,0));
    for(int i=1;i<=n;++i){
        dp[i][100]=dp[i-1][100];
        if(a[i-1]==0) dp[i][100]+=b[i-1];
    
        for(int j=99;j>=0;--j){
            if(a[i-1]+j<=100){
                dp[i][j]=max({
                    dp[i-1][j],
                    dp[i][j+1],
                    dp[i-1][j+a[i-1]]+b[i-1]
                });
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j+1]);
            }
        }
    }
    cout<<dp[n][1];
}
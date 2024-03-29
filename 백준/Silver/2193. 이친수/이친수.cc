#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define mod 1000000000LL
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    dp[1][1]=1;
    if(n>1){
        dp[2][0]=1;
    }
    for(int i=3;i<=n;++i){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    cout<<dp[n][0]+dp[n][1];
}
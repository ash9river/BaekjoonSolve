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
    vector<vector<ll>> dp(n+1,vector<ll>(10,0));
    for(int i=0;i<=9;++i) dp[1][i]=1;
    for(int i=2;i<=n;++i){
        dp[i][0]=dp[i-1][1];
        for(int j=1;j<9;++j){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
        }
        dp[i][9]=dp[i-1][8];
    }
    ll sum=0;
    for(int i=1;i<10;++i){
        sum+=dp[n][i];
        sum=sum%mod;
    }
    cout<<sum;
}
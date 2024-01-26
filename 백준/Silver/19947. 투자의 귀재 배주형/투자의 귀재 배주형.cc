#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int h,y;
    cin>>h>>y;
    vector<int> dp(11,0);
    dp[0]=h;
    for(int i=1;i<min(y+1,3);++i){
        dp[i]=dp[i-1]+dp[i-1]*0.05;
    }
    for(int i=3;i<min(y+1,5);++i){
        dp[i]=max(dp[i-1]+dp[i-1]*0.05,dp[i-3]+dp[i-3]*0.2);
    }
    for(int i=5;i<=10;++i){
        dp[i]=max({dp[i-1]+dp[i-1]*0.05,dp[i-3]+dp[i-3]*0.2,dp[i-5]+dp[i-5]*0.35});
    }
    cout<<dp[y];
}
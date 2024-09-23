#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string a;
    cin>>a;
    vector<vector<int>> dp(2,vector<int>(1000001));
    for(int i=0;i<n;++i){
        dp[0][i]=dp[1][i]=987654321;
    }
    dp[0][0]=a[0]-'A';
    dp[1][0]='B'-a[0];
    for(int i=1;i<n;++i){
        dp[0][i]=min(dp[0][i-1]+a[i]-'A',dp[1][i-1]+1);
        dp[1][i]=min(dp[0][i-1]+1,dp[1][i-1]+'B'-a[i]);
    }
    cout<<dp[0][n-1];
}
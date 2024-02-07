#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> table(n);//{wieght,val}
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    for(int i=0;i<n;++i){
        cin>>table[i].first>>table[i].second;
    }
    for(int i=1;i<=n;++i){ 
    dp[i][k]=dp[i-1][k];
        for(int j=k-1;j>=0;--j){
            if(j+table[i-1].first<=k){
                dp[i][j]=max({
                    dp[i-1][j],
                    dp[i-1][j+1],
                    dp[i-1][j+table[i-1].first]+table[i-1].second
                });
            }
            else{
                dp[i][j]=max(
                    dp[i-1][j],
                    dp[i][j+1]
                );
            }
        }
    }
    cout<<dp[n][0];
}
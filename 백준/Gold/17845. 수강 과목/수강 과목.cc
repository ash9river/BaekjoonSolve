#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001][10001];
int n,k;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    vector<pair<int,int>> v(k); // importance, time of studying 
    for(int i=0;i<k;++i){
        cin>>v[i].first>>v[i].second;
    }
    for(int i=v[0].second;i<=n;++i){
        dp[0][i]=v[0].first;
    }
    for(int i=1;i<k;++i){
        for(int j=0;j<v[i].second;++j){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=v[i].second;j<=n;++j){
            dp[i][j]=max({dp[i-1][j],dp[i-1][j-v[i].second]+v[i].first,dp[i][j-1]});
        }
    }
    cout<<dp[k-1][n];
}
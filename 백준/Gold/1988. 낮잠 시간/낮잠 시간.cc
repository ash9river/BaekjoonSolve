#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int v[3000];
int dp[3001][2][3000];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,b;
    cin>>n>>b;
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=b;++j){
            dp[i][0][j]=max(dp[i-1][0][j],dp[i-1][1][j]);
            dp[i][1][j]=max(dp[i-1][0][j-1],dp[i-1][1][j-1]+v[i-1]);
        }
    }
    cout<<max(dp[n][0][b-1],dp[n][1][b-1]);
}
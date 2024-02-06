#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=v[0];
    for(int i=2;i<=n;++i){
        for(int j=1;j<i;++j){
            if(v[i-1]>v[j-1]){
                dp[i]=max(dp[i],dp[j]);
            }
        }
        dp[i]+=v[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
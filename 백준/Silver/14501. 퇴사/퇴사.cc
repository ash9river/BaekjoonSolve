#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i].first>>v[i].second;
    }
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;--i){
        if(i+v[i].first>n){
            dp[i]=dp[i+1];
            continue;
        }
        dp[i]=v[i].second+dp[i+v[i].first];
        for(int j=i+v[i].first-1;j>i;--j){
            dp[i]=max(dp[i],dp[j]);
        }
    }
    cout<<dp[0];
}
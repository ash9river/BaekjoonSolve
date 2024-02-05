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
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            dp[i]=max(dp[i],dp[i-j]+v[j-1]);
        }
    }
    cout<<dp[n];
}
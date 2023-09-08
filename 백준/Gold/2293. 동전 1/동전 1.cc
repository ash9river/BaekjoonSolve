#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    vector<int> dp(10001,0);
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    dp[0]=1;
    for(int i=0;i<n;++i){
        for(int j=v[i];j<=k;++j){
            dp[j]+=dp[j-v[i]];
        }
    }
    cout<<dp[k];
}
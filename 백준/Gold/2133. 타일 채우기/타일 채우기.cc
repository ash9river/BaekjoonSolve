#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll dp[31];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    dp[0]=1;
    dp[2]=3;
    for(int i=4;i<=30;i+=2){
        dp[i]=dp[i-2]*4-dp[i-4];
    }
    cout<<dp[n];
}
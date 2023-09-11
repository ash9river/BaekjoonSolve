#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;//4% TLE
vector<ll> dp(1000001);
void makeDP(){
    for(int i=1;i<=1000000;++i){
        for(int j=i;j<=1000000;j+=i){
            dp[j]+=i;
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    makeDP();
    for(int i=2;i<=1000000;++i){
        dp[i]+=dp[i-1];
    }
    int t;
    cin>>t;
    vector<int> v(t);
    for(int i=0;i<t;++i){
        cin>>v[i];
    }
    for(int i=0;i<t;++i){
        cout<<dp[v[i]]<<"\n";
    }
}
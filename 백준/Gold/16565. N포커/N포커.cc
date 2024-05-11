#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define MOD 10007
using namespace std;
vector<vector<ll>> c(53,vector<ll>(53,0));
ll binominal(int n,int r){
    if(r==0||r==n) return c[n][r]=1;
    ll& ret=c[n][r];
    if(ret!=0) return ret;
    return ret=binominal(n-1,r-1)+binominal(n-1,r); 
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    ll ans=0;
    for(int i=4;i<=n;i+=4){
        if(i%8==0){
            ans=(ans-(binominal(13,i/4)*binominal(52-i,n-i))%MOD+MOD)%MOD;
        }
        else{
            ans=(ans+(binominal(13,i/4)*binominal(52-i,n-i))%MOD)%MOD;
        }
    }
    cout<<ans;
}
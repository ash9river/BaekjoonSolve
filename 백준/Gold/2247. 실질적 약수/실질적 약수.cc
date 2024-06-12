#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    ll ans=0;
    ll MOD=1000000;
    for(int i=2;i<n;++i){
        if(n/i-1<=0) break;
        ans=(ans+i*(n/i-1)%MOD )%MOD;
    }
    cout<<ans;
}     
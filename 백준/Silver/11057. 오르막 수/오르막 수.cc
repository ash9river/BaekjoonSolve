#include <iostream>
#include <vector>
#include <algorithm>
#define mod 10007
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<vector<int>> v(1001,vector<int>(10,0));
    for(int i=0;i<10;++i){
        v[0][i]=1;
    }
    for(int i=1;i<n;++i){
        for(int j=0;j<10;++j){
            for(int k=j;k<10;++k){
                v[i][j]=(v[i][j]+v[i-1][k])%mod;
            }
        }
    }
    int ans=0;
    for(int i=0;i<10;++i) ans=(ans+v[n-1][i])%mod;
    cout<<ans;
}
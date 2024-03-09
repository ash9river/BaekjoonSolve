#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int x,n;
    cin>>n>>x;
    vector<ll> v(n);
    vector<ll> psum(n+1,0);
    for(int i=0;i<n;++i){
        cin>>v[i];
    } 
    for(int i=1;i<=n;++i){
        psum[i]=psum[i-1]+v[i-1];
    }
    if(psum[n]==0) cout<<"SAD";
    else{
        ll myMax=0;
        for(int i=x;i<=n;++i){
            myMax=max(myMax,psum[i]-psum[i-x]);
        }
        ll maxGae=0;
        for(int i=x;i<=n;++i){
            ll val=psum[i]-psum[i-x];
            if(myMax==val) ++maxGae;
        }
        cout<<myMax<<"\n"<<maxGae;
    }
}
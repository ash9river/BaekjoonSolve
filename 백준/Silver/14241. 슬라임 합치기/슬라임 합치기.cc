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
    vector<ll> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    ll ans=0,sli=0;
    sort(v.begin(),v.end(),greater<>());
    sli=v[0]+v[1];
    ans=v[0]*v[1];
    for(int i=2;i<n;++i){ 
        ans+=sli*v[i];
        sli+=v[i];
    }
    cout<<ans;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;//75%틀
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;++i){
        ll target=v[i];
        for(int j=0;j<n;++j){
            if(i==j) continue;
            ll subTarget=v[j];
            ll rest=target-subTarget;
            int idx=lower_bound(v.begin(),v.end(),rest)-v.begin();
            if(idx>=n) continue;
            int maxIdx=upper_bound(v.begin(),v.end(),rest)-v.begin();
            int gae=maxIdx-idx;
            if(v[idx]!=rest) continue;
            if(v[i]==v[j]){
                if(v[idx]!=0) continue;
                if(v[i]==0){
                    if(gae<3) continue;
                }
            }
            else{
                if(v[j]==v[idx]){
                    if(gae<2) continue;
                }
                if(v[j]==0){
                    if(gae<2) continue;
                }
            }
            ++ans;
            break;
        }
    }
    cout<<ans;
}
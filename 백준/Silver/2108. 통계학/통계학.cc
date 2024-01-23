#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<ll> v(n);
    map<ll,ll> m;
    ll sum=0;
    for(int i=0;i<n;++i){
        cin>>v[i];
        sum+=v[i];
        if(m.find(v[i])==m.end()){
            m[v[i]]=1;
        }
        else{
            m[v[i]]=m[v[i]]+1;
        }
    }
    sort(v.begin(),v.end());
    pair<ll,ll> p={0,0};
    bool state=false;
    for(auto it=m.begin();it!=m.end();++it){
        ll val=it->first;
        ll gae=it->second;
        if(gae>p.first){
            state=false;
            p={gae,val};
        }
        else if(gae==p.first){
            if(!state){
                state=true;
                p.second=val;
            }
        }
    }
    ll rslt=floor(sum/(double)n+0.5);
    cout<<rslt<<"\n"<<v[n/2]<<"\n"<<p.second<<"\n"<<v[n-1]-v[0];
}

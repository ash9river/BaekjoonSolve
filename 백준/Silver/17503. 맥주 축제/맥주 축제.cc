#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n,m,k,a,b;
    cin>>n>>m>>k;
    vector<pair<ll,ll>> v(k);
    for(int i=0;i<k;++i){
        cin>>a>>b;
        v[i]={b,-a}; // level, priority
    }
    sort(v.begin(),v.end());
    priority_queue<ll> q;
    ll sum=0;
    for(int i=0;i<n;++i){
        sum-=v[i].second;
        q.push(v[i].second);
    }
    if(sum>=m){
        cout<<v[n-1].first;
    }
    else{
        bool state=false;
        ll ans=0;
        for(int i=n;i<k;++i){
            sum=sum+q.top()-v[i].second;
            q.pop();
            q.push(v[i].second);
            if(sum>=m){
                state=true;
                ans=v[i].first;
                break;
            }
        }
        if(state){
            cout<<ans;
        }
        else cout<<-1;
    }
}
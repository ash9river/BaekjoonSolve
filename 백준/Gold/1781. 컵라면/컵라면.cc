#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    priority_queue<pair<ll,ll>> q;
    ll ans=0,a,b;
    for(int i=0;i<n;++i){
        cin>>a>>b;//day,gae
        q.push({-a,b});
    }
    vector<ll> v(200001,0);
    int crnDay=1;
    priority_queue<pair<ll,ll>> ansQ; //gae, idx
    while(!q.empty()){
        ll day=-q.top().first;
        ll gae=q.top().second;
        q.pop();
        if(crnDay<=day){
            v[crnDay]=gae;
            ansQ.push({-gae,crnDay});
            crnDay++;
        }
        else{
            int tmpGae=-ansQ.top().first;
            int tmpDay=ansQ.top().second;
            if(gae<tmpGae) continue;
            else{
                v[tmpDay]=gae;
                ansQ.pop();
                ansQ.push({-gae,tmpDay});
            }
        }
    }
    for(int i=1;i<=200000;++i){
        ans+=v[i];
    }
    cout<<ans;
}
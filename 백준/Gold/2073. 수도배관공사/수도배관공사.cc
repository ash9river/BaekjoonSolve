#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int d,p;

    cin>>d>>p;

    vector<pair<ll,ll>> v(p);

    for(int i=0;i<p;++i){
        cin>>v[i].first>>v[i].second; // length, capacity
    }
    
    vector<ll> beforeDP(d+1,0);
    vector<ll> afterDp(d+1,0);

    for(int i=1;i<=p;++i){
        for(int j=0;j<=d;++j){
            afterDp[j]=0;
        }

        for(int j=0;j<v[i-1].first;++j){
            afterDp[j]=beforeDP[j];
        }

        afterDp[v[i-1].first]=beforeDP[v[i-1].first]==0?v[i-1].second:max(beforeDP[v[i-1].first],v[i-1].second);

        for(int j=v[i-1].first+1;j<=d;++j){
            afterDp[j]=max(beforeDP[j],min(beforeDP[j-v[i-1].first],v[i-1].second));
        }

        for(int j=0;j<=d;++j) beforeDP[j]=afterDp[j];
    }

    cout<<afterDp[d];

}
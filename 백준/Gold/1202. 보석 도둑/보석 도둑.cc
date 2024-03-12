#include <iostream>
#include <vector>
#include <set>
#define ll long long
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> j(n);
    multiset<ll> b; // backpack
    int aa,bb;
    for(int i=0;i<n;++i){
        cin>>aa>>bb; // weight, price
        j[i]={-bb,-aa}; // price, weight
    }
    for(int i=0;i<k;++i){
        cin>>aa;
        b.insert(aa);
    }
    sort(j.begin(),j.end());
    ll ans=0;
    for(int i=0;i<n;++i){
        if(b.empty()) break;
        auto it=b.lower_bound(-j[i].second);
        if(it==b.end()) continue;
        ans+=(-j[i].first);
        b.erase(it);
    }
    cout<<ans;
    // 가장 가치가 큰 것들을 순차적으로 고르는데, 배낭의 무게가 안맞으면 skip
    // 배낭의 무게가 맞으면, 가장 배낭의 크기가 가까우면서도 큰거
}
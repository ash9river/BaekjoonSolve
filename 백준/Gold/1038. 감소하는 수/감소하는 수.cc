#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;
deque<ll> v;
void makeDeq(ll depth,ll lastJari,ll val){
    if(depth==0){
        if(lastJari>0){
            for(int i=0;i<lastJari;++i){
                v.push_back(val+i);
            }
            return;
        }
    }
    for(int i=1;i<10;++i){
        if(lastJari<=i) break;
        makeDeq(depth-1,i,(val+i)*10);
    }
}
void init(){
    for(int i=1;i<10;++i){
        makeDeq(i,10,0);
    }
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    for(int i=0;i<10;++i) v.push_back(i);
    init();
    if(n>=v.size()) cout<<-1;
    else cout<<v[n];
}
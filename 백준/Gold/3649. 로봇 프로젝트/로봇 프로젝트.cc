#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
    ll x,n;
    while(cin>>x>>n){
        vector<ll> v(n);
        for(int i=0;i<n;++i){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        vector<ll> table(n+1,0);
        for(int i=1;i<=n;++i){
            table[i]=table[i-1]+v[i-1];
        }
        int lo=0,hi=n-1;
        bool state=false;
        x*=1e7;
        while(lo<hi){
            ll val=v[lo]+v[hi];
            if(val==x){
                cout<<"yes "<<v[lo]<<" "<<v[hi]<<"\n";
                state=true;
                break;
            }
            else if(val>x){
                --hi;
            }
            else ++lo;
        }
        if(!state) cout<<"danger\n";
    }
}
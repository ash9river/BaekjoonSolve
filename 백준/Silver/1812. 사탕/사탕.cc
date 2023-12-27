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
    ll sum=0;
    for(int i=0;i<n;++i){
        cin>>v[i];
        sum+=v[i];
    }
    sum/=2;
    ll subS=0;
    for(int i=0;i<n-2;i+=2){
        subS+=v[i];
    }
    vector<ll> table(n,0);
    table[n-1]=sum-subS;
    for(int i=n-2;i>=0;--i){
        table[i]=v[i]-table[i+1];
    }
    for(int k:table) cout<<k<<"\n";
}
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n,m;
    cin>>n>>m;
    string a;
    cin>>a;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        v[i]=a[i]-'0';
    }
    for(int i=0;i<n-1;++i){
        if(v[i]==0) continue;
        int val=10-v[i];
        if(m>=val){
            m-=val;
            v[i]=0;
        }
    }
    if(m!=0){
        m%=10;
        v[n-1]=(v[n-1]+m)%10;
    }
    for(int i=0;i<n;++i){
        cout<<v[i];
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    vector<int> partialV(n-1);
    for(int i=0;i<n-1;++i){
        partialV[i]=v[i+1]-v[i];
    }
    sort(partialV.begin(),partialV.end());
    long long ans=0;
    for(int i=0;i<n-k;++i){
        ans+=partialV[i];
    }
    cout<<ans;
}
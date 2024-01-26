#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<int> v(n+m);
    for(int i=0;i<n+m;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int k:v) cout<<k<<" ";
}
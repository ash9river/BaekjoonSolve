#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;//3%틀
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    pair<int,int> ptr={0,v[0]};
    int dif=1;
    for(int i=1;i<n;++i){
        if(ptr.second<=v[i]){
            dif=max(dif,i-ptr.first);
            ptr={i,v[i]};
        }
    }
    if(ptr.second>v[n-1]) dif=max(dif,n-ptr.first);
    cout<<dif;
}
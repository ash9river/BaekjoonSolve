#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<int> v;
int n,m;
bool para(int gil){
    int gae=0;
    for(int i=0;i<n;++i){
        gae+=v[i]/gil;
    }
    if(gae>=m) return true;
    return false;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>m>>n;
    v.resize(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int lo=1,hi=v[n-1];
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(para(mid)){
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    cout<<hi;
}
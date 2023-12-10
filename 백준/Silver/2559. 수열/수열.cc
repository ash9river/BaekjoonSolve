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
    int tmpMax;
    int tmp=0;
    for(int i=0;i<k;++i) tmp+=v[i];
    tmpMax=tmp;
    for(int i=1;i<n-k+1;++i){
        tmp-=v[i-1];
        tmp+=v[i+k-1];
        tmpMax=max(tmpMax,tmp);
    }
    cout<<tmpMax;
}
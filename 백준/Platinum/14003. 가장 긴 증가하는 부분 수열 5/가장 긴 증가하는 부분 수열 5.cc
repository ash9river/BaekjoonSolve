#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,tmp,ptr=0;
    cin>>n;
    vector<int> cache(n+1,0);
    vector<int> v(n);
    vector<int> choice(n,0);
    cin>>cache[0];
    v[0]=cache[0];
    for(int i=1;i<n;++i){
        cin>>tmp;
        v[i]=tmp;
        if(tmp>cache[ptr]){
            cache[++ptr]=tmp;
            choice[i]=ptr;
        }
        else{
            int idx=lower_bound(cache.begin(),cache.begin()+ptr,tmp)-cache.begin();
            cache[idx]=tmp;
            choice[i]=idx;
        }
    }
    cout<<ptr+1<<"\n";
    vector<int> ans(ptr+1);
    for(int i=n-1;i>=0;--i){
        if(choice[i]==ptr){
            ans[ptr--]=v[i];
        }
    }
    for(int k:ans) cout<<k<<" ";
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ori[50001];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    vector<int> batry(n);
    for(int i=0;i<n;++i) cin>>batry[i];
    sort(batry.begin(),batry.end());
    for(int i=1;i<=50000;++i) ori[i]=987654321;
    for(int i=0;i<n;++i){
        for(int j=50000;j>0;--j){
            if(ori[j]>0&&ori[j]<k){
                ori[j+batry[i]]=min(ori[j+batry[i]],ori[j]+1);
            }
        }
        ori[batry[i]]=1;
    }
    vector<int> ans;
    for(int i=1;i<50001;++i){
        if(ori[i]!=987654321){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<'\n';
    for(int k:ans) cout<<k<<" ";
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    vector<int> psum(n+1,0);
    for(int i=0;i<n;++i){
        psum[i+1]=psum[i]+v[i];
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        int lo=i,hi=n;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int len1=psum[mid]-psum[i-1];
            int len2=psum[n]-len1;
            if(len1<len2) lo=mid+1;
            else hi=mid-1;
            ans=max(ans,min(len1,len2));
        }
    }
    cout<<ans;
}
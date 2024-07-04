#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,x;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    cin>>x;
    sort(v.begin(),v.end());
    int ans=0,lo=0,hi=n-1;
    while(lo<hi){
        int target=v[lo]+v[hi];
        if(target==x){
            ++ans;
            ++lo;
        }
        else if(target>x){
            --hi;
        }
        else{
            ++lo;
        }
    }
    cout<<ans;
}
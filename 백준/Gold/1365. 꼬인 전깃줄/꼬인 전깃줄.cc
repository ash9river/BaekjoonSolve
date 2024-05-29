#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,a;
    cin>>n;
    deque<int> v;
    cin>>a;
    v.push_back(a);
    int ans=0;
    for(int i=1;i<n;++i){
        cin>>a;
        auto it=lower_bound(v.begin(),v.end(),a);
        if(it==v.end()){
            v.push_back(a);
        }
        else{
            ++ans;
            v[it-v.begin()]=a;
        }
    }
    cout<<ans;
}
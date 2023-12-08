#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,a;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    multiset<int> s;
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>a;
        s.insert(a);
    }
    int time=0;
    if(v[n-1]<*s.rbegin()){
        cout<<-1;
    }
    else{
        while(!s.empty()){
            for(int i=0;i<n;++i){
                if(s.empty()) break;
                auto tmp=s.lower_bound(v[i]);
                if(tmp==s.end()||*tmp>v[i]){
                    if(tmp==s.begin()) continue;
                    --tmp;
                }
                s.erase(tmp);
            }   
            ++time;
        }
        cout<<time;
    }
}
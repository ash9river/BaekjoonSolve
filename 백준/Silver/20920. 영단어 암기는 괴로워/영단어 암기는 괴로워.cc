#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    map<string,int> m;
    int n,mGil;
    cin>>n>>mGil;
    string a;
    for(int i=0;i<n;++i){
        cin>>a;
        if(a.size()<mGil) continue;
        if(m.count(a)>0){
            m[a]=m[a]+1;
        }
        else m[a]=1;
    }
    vector<tuple<int,int,string>> v(m.size());
    int idx=0;
    for(auto it=m.begin();it!=m.end();++it){
        string str=it->first;
        int gae=it->second;
        v[idx++]={-gae,-str.size(),str};
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i) cout<<get<2>(v[i])<<"\n";
}
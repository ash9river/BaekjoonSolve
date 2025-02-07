#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    map<string,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string a;
        cin>>a;
        if(m.count(a)>0){
            m[a]=m[a]+1;
        }
        else m[a]=1;
    }
    pair<int,string> ans={-1,""};
    for(auto it=m.begin();it!=m.end();++it){
        string val=it->first;
        int gae=it->second;
        if(gae>ans.first){
            ans={gae,val};
        }
    }
    cout<<ans.second;
}
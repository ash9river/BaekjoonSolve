#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    string a,b;
    int n;
    cin>>n;
    set<string> s;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        if(b=="enter"){
            s.insert(a);
        }
        else{
            s.erase(a);
        }
    }
    int p=s.size();
    vector<string> v(p);
    int ptr=0;
    for(auto k:s){
        v[ptr]=k;
        ++ptr;
    }
    sort(v.begin(),v.end(),greater<>());
    for(int i=0;i<p;++i){
        cout<<v[i]<<"\n";
    }
}
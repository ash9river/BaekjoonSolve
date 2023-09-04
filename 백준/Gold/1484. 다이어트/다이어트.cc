#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
set<int> s;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int g;
    cin>>g;
    for(int i=1;i<50000;++i){
        for(int j=i+1;j<=50000;++j){
            int tmp=(i+j)*(j-i);
            if(tmp>100000) break;
            if(tmp==g) s.insert(j);
        }
    }
    if(s.size()==0) cout<<-1;
    else for(int k:s) cout<<k<<'\n';
}
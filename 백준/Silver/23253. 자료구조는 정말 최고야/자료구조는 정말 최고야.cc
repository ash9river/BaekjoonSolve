#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    bool state=true;
    for(int i=0;i<m;++i){
        int k;
        cin>>k;
        cin>>v[0];
        for(int j=1;j<k;++j){
            cin>>v[j];
            if(v[j]>v[j-1]) state=false;
        }
    }
    if(state) cout<<"Yes";
    else cout<<"No";
}
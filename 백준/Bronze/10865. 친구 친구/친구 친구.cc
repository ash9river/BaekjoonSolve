#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<int> v(n+1,0);
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        v[a]++;
        v[b]++;
    }
    for(int i=1;i<=n;++i){
        cout<<v[i]<<"\n";
    }
}
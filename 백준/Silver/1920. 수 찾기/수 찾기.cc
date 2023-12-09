#include <iostream>
#include <vector>
#include <set>
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
    sort(v.begin(),v.end());
    int m;
    cin>>m;
    int a;
    for(int i=0;i<m;++i){
        cin>>a;
        if(binary_search(v.begin(),v.end(),a)) cout<<"1\n";
        else cout<<"0\n";
    }
}
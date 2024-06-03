#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> v(n);
    vector<pair<int,int>> table(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    for(int i=0;i<n;++i){
        table[i].second=v[i];
        for(int j=0;j<n;++j){
            table[i].first+=abs(v[i]-v[j]);
        }
    }
    sort(table.begin(),table.end());
    cout<<table[0].second;
}
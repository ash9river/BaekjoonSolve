#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> v(n);
    stack<pair<int,int>> s;
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    vector<int> ans(n);
    s.push({v[n-1],n-1});
    for(int i=n-2;i>=0;--i){
        while(true){
            if(s.empty()||s.top().first>v[i]) break;
            ans[s.top().second]=i+1;
            s.pop();
        }
        s.push({v[i],i});
    }
    for(int k:ans) cout<<k<<" ";
}
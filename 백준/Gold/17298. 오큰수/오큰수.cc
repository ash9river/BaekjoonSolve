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
    stack<int> s;
    vector<int> ans(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    for(int i=n-1;i>=0;--i){
        while(!s.empty()){
            int t=s.top();
            if(v[i]<t){
                ans[i]=t;
                break;
            }
            else{
                s.pop();
            }
        }
        if(ans[i]==0){
            ans[i]=-1;
        }
            s.push(v[i]);
    }
    for(int k:ans) cout<<k<<" ";
}
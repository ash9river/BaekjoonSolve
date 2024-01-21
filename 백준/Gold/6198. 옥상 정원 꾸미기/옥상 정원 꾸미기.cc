#include <iostream>
#include <stack>
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
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    stack<int> s;
    ll sum=0;
    for(int i=0;i<n;++i){
        if(s.empty()){
            s.push(v[i]);
            continue;
        }
        while(!s.empty()&&s.top()<=v[i]){
            s.pop();
        }
        sum+=s.size();
        s.push(v[i]);
    }
    cout<<sum;
}
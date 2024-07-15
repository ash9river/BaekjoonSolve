#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    stack<int> s;
    int n,ptr=1;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    bool state=true;
    for(int i=0;i<n;++i){
        if(ptr==v[i]){
            ++ptr;
        }
        else{
            while(!s.empty()){
                int pk=s.top();
                if(ptr==pk){
                    s.pop();
                    ++ptr;
                }
                else break;
            }
            s.push(v[i]);
        }
    }
    while(!s.empty()){
        int pk=s.top();
        if(ptr==pk){
            s.pop();
            ++ptr;
        }
        else break;
    }
    if(!s.empty()) cout<<"Sad";
    else cout<<"Nice";
}
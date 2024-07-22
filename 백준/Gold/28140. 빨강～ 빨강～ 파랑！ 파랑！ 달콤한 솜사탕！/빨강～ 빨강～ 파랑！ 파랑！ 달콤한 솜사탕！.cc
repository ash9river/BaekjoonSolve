#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string str;
    int n,q;
    cin>>n>>q>>str;
    deque<int> r;
    deque<int> b;
    for(int i=0;i<str.size();++i){
        if(str[i]=='R'){
            r.push_back(i);
        }
        else if(str[i]=='B'){
            b.push_back(i);
        }
    }
    int L,R;
    for(int i=0;i<q;++i){
        cin>>L>>R;
        int ansA=lower_bound(r.begin(),r.end(),L)-r.begin();
        if(ansA==r.size()){
            cout<<"-1\n";
            continue;
        }
        int ansB=lower_bound(r.begin(),r.end(),r[ansA]+1)-r.begin();
        if(ansB==r.size()){
            cout<<"-1\n";
            continue;
        }
        int ansC=lower_bound(b.begin(),b.end(),r[ansB]+1)-b.begin();
        if(ansC==b.size()){
            cout<<"-1\n";
            continue;
        }
        int ansD=lower_bound(b.begin(),b.end(),b[ansC]+1)-b.begin();
        if(ansD==b.size()||b[ansD]>R){
            cout<<"-1\n";
            continue;
        }
        cout<<r[ansA]<<" "<<r[ansB]<<" "<<b[ansC]<<" "<<b[ansD]<<"\n";
    }
}
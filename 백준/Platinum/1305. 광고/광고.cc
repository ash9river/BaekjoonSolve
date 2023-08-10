#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//8% 틀
vector<int> partialMatch(const string& str){
    int n=str.size();
    vector<int> pi(n,0);
    int begin=1,matched=0;
    while(begin+matched<n){
        if(str[begin+matched]==str[matched]){
            ++matched;
            pi[begin+matched-1]=matched;
        }
        else{
            if(matched==0) ++begin;
            else{
                begin+=matched-pi[matched-1];
                matched=pi[matched-1];
            }
        }
    }
    return pi;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int l;
    string str;
    cin>>l;
    cin>>str;
    vector<int> k=partialMatch(str);
    cout<<l-k[l-1];
}
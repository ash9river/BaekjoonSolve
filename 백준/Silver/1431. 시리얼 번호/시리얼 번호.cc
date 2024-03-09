#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a,string b){
    if(a.size()>b.size()) return false;
    if(a.size()<b.size()) return true;
    int aCount=0,bCount=0;
    for(int i=0;i<a.size();++i){
        if(a[i]>='0'&&a[i]<='9'){
            aCount+=a[i]-'0';
        }
    }
    for(int i=0;i<b.size();++i){
        if(b[i]>='0'&&b[i]<='9'){
            bCount+=b[i]-'0';
        }
    }
    if(aCount>bCount) return false;
    if(aCount<bCount) return true;
    return a<b;

}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),cmp);
    for(string k:v) cout<<k<<"\n";
}
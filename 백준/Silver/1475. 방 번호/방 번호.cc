#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a;
    cin>>a;
    vector<int> v(10,0);
    for(int i=0;i<a.size();++i){
        if(a[i]=='9') v[6]++;
        else v[a[i]-'0']++;
    }
    if(v[6]%2!=0) {
        v[6]/=2;
        v[6]++;

    }else v[6]/=2;

    int maxVal=0;
    for(int i=0;i<10;++i){
        maxVal=max(maxVal,v[i]);
    }
    cout<<maxVal;
}
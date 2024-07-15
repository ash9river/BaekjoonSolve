#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a,b;
    cin>>a>>b;
    if(a.size()<b.size()){
        swap(a,b);
    }
    string tmpA="",tmpB="";
    for(int i=0;i<b.size();++i){
        tmpA+=a;
    }
    for(int i=0;i<a.size();++i){
        tmpB+=b;
    }
    if(tmpA==tmpB) cout<<1;
    else cout<<0;
}
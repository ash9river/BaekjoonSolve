#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int k;
    cin>>k;
    int s=1,lo=0,tmp=0;
    for(int i=31;i>=0;--i){
        if(k&(1<<i)){
            if(k==(1<<i)){
                tmp=i;
                s=(1<<i);
            }
            else{
                tmp=i+1;
                s=(1<<(i+1));
            }
            break;
        }
    }
    for(int i=0;i<32;++i){
        if(k&(1<<i)){
            lo=tmp-i;
            break;
        }
    }
    cout<<s<<" "<<lo;
}
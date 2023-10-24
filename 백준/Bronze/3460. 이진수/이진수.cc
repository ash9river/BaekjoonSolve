#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t,n;
    cin>>t;
    while(t-->0){
        cin>>n;
        for(int i=0;i<32;++i){
            if(n&(1<<i)) cout<<i<<" ";
        }
        cout<<'\n';
    }
}
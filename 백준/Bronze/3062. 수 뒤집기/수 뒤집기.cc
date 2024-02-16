#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t-->0){
        int a,b=0,tmp;
        cin>>a;
        tmp=a;
        while(tmp>0){
            b*=10;
            b+=tmp%10;
            tmp/=10;
        }
        int sum=a+b;
        string str=to_string(sum);
        string strTmp=str;
        reverse(strTmp.begin(),strTmp.end());
        if(str==strTmp) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
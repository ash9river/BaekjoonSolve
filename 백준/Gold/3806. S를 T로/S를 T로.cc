#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        string a,b;
        cin>>a>>b;
        int zeroA=0,oneA=0,qt=0,zeroB=0,oneB=0;
        int kai=0,changeV=0;
        for(int i=0;i<a.size();++i){
            if(a[i]=='0'){
                ++zeroA;
            }
            else if(a[i]=='1'){
                ++oneA;
            }
            else{
                ++qt;
            }
            if(b[i]=='0') ++zeroB;
            else ++oneB;
            if(a[i]!=b[i]){
                if(a[i]=='0'){
                    ++kai;
                }
                else if(a[i]=='1'){
                    ++changeV;
                }
            }
        }
        cout<<"Case "<<i<<": ";
        if(zeroA+qt<zeroB){
            cout<<"-1\n";
        }
        else{
            int result=0;
            if(changeV>0){
                if(changeV-kai>0){
                    result=qt+changeV;
                }
                else if(changeV==kai){
                    result=changeV+qt;
                }
                else{
                    result=kai+qt;
                }
            }
            else{
                result=kai+qt;
            }
            cout<<result<<"\n";
        }
    }
}
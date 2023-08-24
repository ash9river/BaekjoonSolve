#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string str;
    string a;
    cin>>str;
    cin>>a;
    int strSize=str.size();
    string b;
    int aSize=a.size();
    char lastWor=a[aSize-1];
    for(int i=0;i<strSize;++i){
        b+=str[i];
        int bSize=b.size();
        if(str[i]==lastWor&&bSize>=aSize){
        bool state=true;
            for(int j=0;j<aSize;++j){
                if(b[bSize-1-j]!=a[aSize-1-j]){
                    state=false;
                    break;
                }
            }
            if(state){
                for(int i=0;i<aSize;++i) b.pop_back();
            }
        }
    }
    if(b=="") cout<<"FRULA";
    else cout<<b;

}
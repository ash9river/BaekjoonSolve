#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a;
    cin>>a;
    bool state=true;
    for(int i=0;i<a.size();++i){
        if(a[i]=='p'){
            if(i+1<a.size()&&a[i+1]=='i'){
                ++i;
            }
            else{
                state=false;
                break;
            }

        }
        else if(a[i]=='k'){
            if(i+1<a.size()&&a[i+1]=='a'){
                ++i;
            }
            else{
                state=false;
                break;
            }

        }
        else if(a[i]=='c'){
            if(i+2<a.size()&&a[i+1]=='h'&&a[i+2]=='u'){
                i+=2;
            }else{
                state=false;
                break;
            }
        }
        else{
            state=false;
            break;
        }
    }
    if(state) cout<<"YES";
    else cout<<"NO";
}
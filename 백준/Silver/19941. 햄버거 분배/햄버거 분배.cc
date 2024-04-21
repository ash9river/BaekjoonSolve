#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    string a;
    cin>>a;
    vector<bool> visited(n,false);
    int ans=0;
    for(int i=0;i<a.size();++i){
        if(a[i]=='P'){
            bool state=false;
            int ptr=i-k;
            if(i-k<0){
                ptr=0;
            }
            for(int j=ptr;j<i;++j){
                if(!visited[j]&&a[j]=='H'){
                    visited[j]=true;
                    state=true;
                    ++ans;
                    break;
                }
            }
            if(!state){
                for(int j=i+1;j<=i+k&&j<n;++j){
                    if(!visited[j]&&a[j]=='H'){
                        visited[j]=true;
                        ++ans;
                        break;
                    }
                }
            }
        }
    }
    cout<<ans;
}
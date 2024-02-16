#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string str,tmp;
    cin>> str;
    tmp=str;
    reverse(tmp.begin(),tmp.end());
    if(str==tmp) cout<<1;
    else cout<<0;
}
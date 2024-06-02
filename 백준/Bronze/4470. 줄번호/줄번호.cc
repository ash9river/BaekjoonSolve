#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string str;
    cin.ignore();
    for(int i=1;i<=n;++i){
        getline(cin,str);
        cout<<i<<". "<<str<<"\n";
    }
}
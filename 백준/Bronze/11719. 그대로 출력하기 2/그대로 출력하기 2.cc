#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(1){
        string tmp="";
        getline(cin,tmp);
        if(cin.eof()) break;
        cout<<tmp<<"\n";
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int table[26][200001];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a;
    cin>>a;
    for(int i=0;i<a.size();++i){
        ++table[a[i]-'a'][i+1];
        for(int j=0;j<26;++j){
            table[j][i+1]+=table[j][i];
        }
    }
    int q;
    cin>>q;
    while(q-->0){
        char p;
        int x,y;
        cin>>p>>x>>y;
        cout<<table[p-'a'][y+1]-table[p-'a'][x]<<"\n";
    }
}
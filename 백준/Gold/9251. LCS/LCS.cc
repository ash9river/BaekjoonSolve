#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a,b;
    cin>>a>>b;
    int aSize=a.size();
    int bSize=b.size();
    vector<vector<int>> table(aSize+1,vector<int>(bSize+1,0));
    for(int i=1;i<=aSize;++i){
        for(int j=1;j<=bSize;++j){
            if(a[i-1]==b[j-1]){
                table[i][j]=table[i-1][j-1]+1;
            }
            else table[i][j]=max(table[i][j-1],table[i-1][j]);
        }
    }
    cout<<table[aSize][bSize];
}
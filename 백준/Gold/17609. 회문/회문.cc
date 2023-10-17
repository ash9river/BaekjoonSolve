#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string str;
int lo,hi;
pair<bool,bool> pandan(int lo,int hi,bool kai,bool usa){
    if(lo>=hi) return {kai,usa};
    if(str[lo]==str[hi]){
        return pandan(lo+1,hi-1,kai,usa);
    }
    else{
        if(!kai){
            return {false,false};
        }
        else kai=false;
        
        pair<bool,bool> left=pandan(lo+1,hi,kai,usa);
        pair<bool,bool> right=pandan(lo,hi-1,kai,usa);
        if(left.second||right.second) return {false,true};
        else return {false,false};
    }
}



void init(){
    bool kai=true,usa=true;
    pair<bool,bool> ans=pandan(lo,hi,kai,usa);
    if(ans.first&&ans.second){
        cout<<"0\n";
    }
    else if(ans.second){
        cout<<"1\n";
    }
    else cout<<"2\n";
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t-->0){
        cin>>str;
        int strSize=str.size();
        lo=0;
        hi=strSize-1;
        init();   
    }
}
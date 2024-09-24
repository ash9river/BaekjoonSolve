#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <string>
#include <algorithm>
using namespace std; // 5%틀
int isNumber(char a){
    int val;
    if(a>='0'&&a<='9'){
        val=a-'0';
    }else{
        val=a-'A'+10;
    }
    return val;
}
pair<char,char> threeSum(char a,char b,char c){
    int aVal,bVal,cVal;
    aVal=isNumber(a);
    bVal=isNumber(b);
    cVal=isNumber(c);
    int ans=aVal+bVal+cVal;
    char retChar='0';
    if(ans>=36){
        ans-=36;
        retChar='1';
    }
    char retAns=ans+'0';
    if(ans>=10) retAns=ans-10+'A';
    return make_pair(retAns,retChar);
}

string makeSum(string a,string b){
    if(a.size()==0||b.size()==0){
        if(a.size()==0&&b.size()==0) return "0";
        return a.size()==0?b:a;
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string ans="";
    char tmp='0';
    for(int i=0;i<min(a.size(),b.size());++i){
        pair<char,char> tmpAns=threeSum(a[i],b[i],tmp);
        ans+=tmpAns.first;
        tmp=tmpAns.second;
    }
    if(a.size()<b.size()) swap(a,b);
    if(tmp=='1'){
        if(a.size()==b.size()) ans+='1';
        else{
            for(int i=min(a.size(),b.size());i<max(a.size(),b.size());++i){
                pair<char,char> tmpAns=threeSum(a[i],tmp,'0');
                ans+=tmpAns.first;
                tmp=tmpAns.second;
            }
            if(tmp=='1') ans+='1';
        }
    }
    else{
        for(int i=min(a.size(),b.size());i<max(a.size(),b.size());++i){
            ans+=a[i];
        }
    }
    reverse(ans.begin(),ans.end()); 
    return ans;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    cin>>k;
    vector<vector<int>> table(36,vector<int>(51,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<v[i].size();++j){
            if(v[i][j]>='0'&&v[i][j]<='9'){
                int jLen=v[i].size()-j;
                ++table[v[i][j]-'0'][jLen];
            }
            else{
                int jLen=v[i].size()-j;
                ++table[v[i][j]-'A'+10][jLen];
            }
        }
    }
    priority_queue<tuple<int,vector<char>,char>> q;
    for(int i=0;i<36;++i){
        string tmpSum="";
        for(int j=1;j<=50;++j){
            if(table[i][j]!=0){
                for(int l=0;l<table[i][j];++l){
                    string tmpVal="";
                    char tmpChar;
                    if(i<26) tmpChar='Z'-i;
                    else tmpChar='0'+35-i;
                    tmpVal+=tmpChar;
                    for(int m=1;m<j;++m){
                        tmpVal+="0";
                    }
                    tmpSum=makeSum(tmpSum,tmpVal);
                }
            }
        }
        if(tmpSum.size()==0||i==35) continue;
        char tmpQChar=i+'0';
        if(i>=10) tmpQChar='A'+i-10;
        vector<char> charV(tmpSum.size());
        for(int i=0;i<tmpSum.size();++i){
            charV[i]=tmpSum[i];
        }
        q.push({charV.size(),charV,tmpQChar});
    }
    if(q.size()<k) k=q.size();
    set<char> charTable;
    while(k-->0){
        char target=get<2>(q.top());
        q.pop();
        charTable.insert(target);
    }
    string ans="";
    for(int i=0;i<36;++i){
        char target;
        if(i<10) target='0'+i;
        else target='A'+i-10;
        if(charTable.find(target)!=charTable.end()){
            target='Z';
        }
        if(target=='0') continue;
        string tmpAns="";
        for(int j=1;j<51;++j){
            if(table[i][j]!=0){
                for(int l=0;l<table[i][j];++l){
                    string tmpVal="";
                    tmpVal+=target;
                    for(int m=1;m<j;++m){
                        tmpVal+="0";
                    }
                    tmpAns=makeSum(tmpAns,tmpVal);
                }
            }
        }
        ans=makeSum(ans,tmpAns);
    }
    cout<<ans;
}
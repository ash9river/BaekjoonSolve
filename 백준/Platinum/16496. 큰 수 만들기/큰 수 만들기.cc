#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long
using namespace std;
vector<string> v;
bool cmp(const string& a,const string& b){
    if(a.size()==b.size()){
        if(stoi(a)>=stoi(b)) return true;
        else return false;
    }
    else if(a.size()<b.size()){
        for(int i=0;i<a.size();i++){
            int A=a[i]-48;
            int B=b[i]-48;
            if(A>B) return true;
            else if(A<B) return false;
            else continue;
        }
        string first="";
        first=first.append(a).append(b);
        string second="";
        second=second.append(b).append(a);
        ull p=stoull(first);
        ull q=stoull(second);
        if(p>q) return true;
        else return false;
    }
    else{
        for(int i=0;i<b.size();i++){
            int A=a[i]-48;
            int B=b[i]-48;
            if(A>B) return true;
            else if(A<B) return false;
            else continue;
        }
        string first="";
        first=first.append(a).append(b);
        string second="";
        second=second.append(b).append(a);
        ull p=stoull(first);
        ull q=stoull(second);
        if(p>q) return true;
        else return false;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        v.push_back(str);
    }
    sort(v.begin(),v.end(),cmp);
    bool state=true;
    for(int i=0;i<v.size();i++){
        if(v[i]!="0"){
            state=false;
            break;
        } 
    }
    if(state) cout<<0;
    else{
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
    }
}
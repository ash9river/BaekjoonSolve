#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a;
    cin>>a;
    map<int,int> m;
    for(int i=0;i<a.size();++i){
        int tmp=a[i]-'A';
        if(m.count(tmp)>0){
            m[tmp]=m[tmp]+1;
        }
        else m[tmp]=1;
    }
    if(a.size()%2==0){
        bool state=true;
        for(auto it=m.begin();it!=m.end();++it){
            if(it->second%2==1){
                state=false;
                break;
            }
        }
        if(!state) cout<<"I'm Sorry Hansoo";
        else{
            string ans="";
            for(auto it=m.begin();it!=m.end();++it){
                char word=it->first+'A';
                int idx=it->second;
                for(int i=0;i<idx/2;++i){
                    ans+=word;
                }
            }
            for(int i=0;i<ans.size();++i){
                cout<<ans[i];
            }
            for(int i=ans.size()-1;i>=0;--i){
                cout<<ans[i];
            }
        }
    }
    else{
        bool state=true;
        bool ansState=true;
        int tmpIdx=-1;
        for(auto it=m.begin();it!=m.end();++it){
            if(it->second%2==1){
                if(!state){
                    ansState=false;
                    break;
                }
                state=false;
                tmpIdx=it->first;
            }
        }
        if(!ansState) cout<<"I'm Sorry Hansoo";
        else if(!state){
            string ans="";
            for(auto it=m.begin();it!=m.end();++it){
                char word=it->first+'A';
                int idx=it->second;
                for(int i=0;i<idx/2;++i){
                    ans+=word;
                }
            }
            for(int i=0;i<ans.size();++i){
                cout<<ans[i];
            }
            char p=tmpIdx+'A';
            cout<<p;
            for(int i=ans.size()-1;i>=0;--i){
                cout<<ans[i];
            }
        }
        else{
            string ans="";
            for(auto it=m.begin();it!=m.end();++it){
                char word=it->first+'A';
                int idx=it->second;
                for(int i=0;i<idx/2;++i){
                    ans+=word;
                }
            }
            for(int i=0;i<ans.size();++i){
                cout<<ans[i];
            }
            for(int i=ans.size()-1;i>=0;--i){
                cout<<ans[i];
            }
        }
    }
}
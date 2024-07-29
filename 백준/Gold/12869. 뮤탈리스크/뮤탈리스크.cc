#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dp[61][61][61];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    fill(&dp[0][0][0],&dp[60][60][61],987654321);
    vector<int> v(3,0);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    priority_queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,v[0]},{v[1],v[2]}});
    while(!q.empty()){
        int time=-q.top().first.first;
        int a=q.top().first.second;
        int b=q.top().second.first;
        int c=q.top().second.second;
        q.pop();
        if(a==0&&b==0&&c==0){
            dp[0][0][0]=time;
            break;
        }
        vector<int> tmp(3,0);
        int nxtTime=time+1;
        // 9 3 1
        tmp[0]=max(a-9,0);
        tmp[1]=max(b-3,0);
        tmp[2]=max(c-1,0);
        sort(tmp.begin(),tmp.end());
        if(dp[tmp[0]][tmp[1]][tmp[2]]>nxtTime){
            dp[tmp[0]][tmp[1]][tmp[2]]=nxtTime;
            q.push({{-nxtTime,tmp[0]},{tmp[1],tmp[2]}});
        }
        // 9 1 3
        tmp[0]=max(a-9,0);
        tmp[1]=max(b-1,0);
        tmp[2]=max(c-3,0);
        sort(tmp.begin(),tmp.end());
        if(dp[tmp[0]][tmp[1]][tmp[2]]>nxtTime){
            dp[tmp[0]][tmp[1]][tmp[2]]=nxtTime;
            q.push({{-nxtTime,tmp[0]},{tmp[1],tmp[2]}});
        }
        // 3 9 1
        tmp[0]=max(a-3,0);
        tmp[1]=max(b-9,0);
        tmp[2]=max(c-1,0);
        sort(tmp.begin(),tmp.end());
        if(dp[tmp[0]][tmp[1]][tmp[2]]>nxtTime){
            dp[tmp[0]][tmp[1]][tmp[2]]=nxtTime;
            q.push({{-nxtTime,tmp[0]},{tmp[1],tmp[2]}});
        }
        // 3 1 9
        tmp[0]=max(a-3,0);
        tmp[1]=max(b-1,0);
        tmp[2]=max(c-9,0);
        sort(tmp.begin(),tmp.end());
        if(dp[tmp[0]][tmp[1]][tmp[2]]>nxtTime){
            dp[tmp[0]][tmp[1]][tmp[2]]=nxtTime;
            q.push({{-nxtTime,tmp[0]},{tmp[1],tmp[2]}});
        }
        // 1 3 9
        tmp[0]=max(a-1,0);
        tmp[1]=max(b-3,0);
        tmp[2]=max(c-9,0);
        sort(tmp.begin(),tmp.end());
        if(dp[tmp[0]][tmp[1]][tmp[2]]>nxtTime){
            dp[tmp[0]][tmp[1]][tmp[2]]=nxtTime;
            q.push({{-nxtTime,tmp[0]},{tmp[1],tmp[2]}});
        }
        // 1 9 3
        tmp[0]=max(a-1,0);
        tmp[1]=max(b-9,0);
        tmp[2]=max(c-3,0);
        sort(tmp.begin(),tmp.end());
        if(dp[tmp[0]][tmp[1]][tmp[2]]>nxtTime){
            dp[tmp[0]][tmp[1]][tmp[2]]=nxtTime;
            q.push({{-nxtTime,tmp[0]},{tmp[1],tmp[2]}});
        }
    }
    cout<<dp[0][0][0];
}
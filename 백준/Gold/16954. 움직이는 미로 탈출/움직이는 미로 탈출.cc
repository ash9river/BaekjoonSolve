#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#define ll long long
using namespace std;
bool visited[100][8][8];
int dy[9]={
  -1,-1,-1,0,0,0,1,1,1
};
int dx[9]={
  -1,0,1,-1,0,1,-1,0,1
};
bool set(pair<int,int>& order,vector<string>& board,int time){
  if(order.first<0||order.first>7||order.second<0||order.second>7) return false;
  if(visited[time][order.first][order.second]) return false;
  if(board[order.first][order.second]=='#') return false;
  if(order.first>0){
    if(board[order.first-1][order.second]=='#') return false;
  }
  return true;
}

int main(){
  vector<string> v(8);
  for(int i=0;i<8;++i){
    cin>>v[i];
  }
  priority_queue<pair<int,pair<pair<int,int>,vector<string>>>> q;
  q.push({0,{{7,0},v}});
  visited[0][7][0]=true;
  bool state=false;
  while(!q.empty()){
    int time=-q.top().first;
    pair<int,int> start=q.top().second.first;
    vector<string> board=q.top().second.second;
    q.pop();
    for(int i=0;i<9;++i){
      pair<int,int> nxt={start.first+dy[i],start.second+dx[i]};
      int nxtTime=time+1;
      if(set(nxt,board,nxtTime)){
        visited[nxtTime][nxt.first][nxt.second]=true;
        if(nxt.first==0&&nxt.second==7){
          state=true;
          q=priority_queue<pair<int,pair<pair<int,int>,vector<string>>>>();
          break;
        }
        vector<string> newBorad(8);
        newBorad[0]="........";
        for(int i=1;i<8;++i){
          newBorad[i]=board[i-1];
        }
        q.push({-nxtTime,{nxt,newBorad}});
      }
    }
  }
  cout<<state;
}
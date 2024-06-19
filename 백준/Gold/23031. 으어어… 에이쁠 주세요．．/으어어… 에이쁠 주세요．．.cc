#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;//1퍼틀
vector<vector<bool>> flashed(15,vector<bool>(15,false));
vector<vector<char>> v(15,vector<char>(15));
int dy[4]={1,0,-1,0};
int dx[4]={0,-1,0,1};
int n;

bool isValid(int y,int x){
    if(y<0||y>=n||x<0||x>=n) return false;
    return true;
}

void turnOnTheSwitch(int y,int x){
    for(int i=-1;i<=1;++i){
        for(int j=-1;j<=1;++j){
            if(isValid(y+i,x+j)){
                flashed[y+i][x+j]=true;
            }
        }
    }
}
void catGo(pair<int,int>& cat,int direction){
    int ny=cat.first+dy[direction];
    int nx=cat.second+dx[direction];
    if(isValid(ny,nx)){
        cat={ny,nx};
    }
}
void zombieGo(pair<int,int>& zombieCat,bool& direct){
    int go=0;
    if(direct) go=2;  
    int ny=zombieCat.first+dy[go];
    int nx=zombieCat.second+dx[go];
    if(isValid(ny,nx)){
        zombieCat={ny,nx};
    }
    else direct=!direct;
}
bool zombieDirec[40];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a,tmp;
    cin>>n>>a;
    vector<pair<int,int>> zombieCat;
    for(int i=0;i<n;++i){
        cin>>tmp;
        for(int j=0;j<n;++j){
            v[i][j]=tmp[j];
            if(tmp[j]=='Z'){
                v[i][j]='O';
                zombieCat.push_back({i,j});
            }
        }
    }
    int direc=0;
    bool ans=false;
    pair<int,int> cat={0,0};
    for(int q=0;q<a.size();++q){
        if(a[q]=='F'){
            // 전진
            catGo(cat,direc);
            // 스위치가 있는지 판별
            if(v[cat.first][cat.second]=='S'){
                turnOnTheSwitch(cat.first,cat.second);
            }
        }
        else if(a[q]=='L'){
            if(direc==0) direc=3;
            else --direc;
        }
        else{
            if(direc==3) direc=0;
            else ++direc;
        }
            // 좀비 판별
            for(int i=0;i<zombieCat.size();++i){
                if(zombieCat[i].first==cat.first&&zombieCat[i].second==cat.second){
                    if(!flashed[cat.first][cat.second]) ans=true;                 
                }
            }
            // 좀비 전진
            for(int i=0;i<zombieCat.size();++i){
                zombieGo(zombieCat[i],zombieDirec[i]);
            }
            // 좀비판별다시
            for(int i=0;i<zombieCat.size();++i){
                if(zombieCat[i].first==cat.first&&zombieCat[i].second==cat.second){
                    if(!flashed[cat.first][cat.second]) ans=true;                 
                }
            }        
    }

    if(ans){
        cout<<"Aaaaaah!";
    }
    else cout<<"Phew...";
}
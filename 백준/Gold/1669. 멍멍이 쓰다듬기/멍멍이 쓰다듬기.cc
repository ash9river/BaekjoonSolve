#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int x,y;
    cin>>x>>y;
    y-=x;
    x=0;
    int day=1;
    if(x==y) day=0;
    if(y%2==0){
        y/=2;
        while(y>0){
            if(day>y&&y*2>day){
                day=day*2;
                break;
            }
            if(day==y){
                day=day*2;
                break;
            }
            else if(day>y){
                day=(day-1)*2+1;
                break;
            }
            y-=day;
            ++day;
        }
    }
    else{
        while(y>0){
            if(day*2==y){
                day=day*2+1;
                break;
            }
            else if(day*2>y&&y>day){
                day=day*2;
                break;
            }
            else if(day==y){
                day=(day-1)*2+1;
                break;
            }
            else if(day>y){
                day=(day-1)*2+1;
                break;
            }
            y-=day*2;
            ++day;
        }


    }
    cout<<day;
}
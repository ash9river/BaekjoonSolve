#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    double sum=0;
    double hak=0;
    while(true){
        string a;
        double b;
        cin>>a>>b>>a;
        if(cin.eof()) break;
        if(a=="P") continue;
        else if(a=="A+") sum+=b*4.5;
        else if(a=="A0") sum+=b*4.0;
        else if(a=="B+") sum+=b*3.5;
        else if(a=="B0") sum+=b*3.0;
        else if(a=="C+") sum+=b*2.5;
        else if(a=="C0") sum+=b*2.0;
        else if(a=="D+") sum+=b*1.5;
        else if(a=="D0") sum+=b;
        hak+=b;
    }
    cout<<sum/hak;
}
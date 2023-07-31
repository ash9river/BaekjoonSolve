#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
ll r=31,m=1234567891;
ll result;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
	int l;
	cin>>l;
    string str;
	cin>>str;
	vector<ll> a(str.size());
	vector<ll> powR(str.size(),0);
	powR[0]=1;
	for(int i=1;i<powR.size();++i){
		powR[i]=r*powR[i-1]%m;
	} 
	for(int i=0;i<a.size();++i){
		a[i]=str[i]-'a'+1;
	}
	for(int i=0;i<a.size();++i){
		result+=a[i]*powR[i]%m;
	}
	cout<<result;
}
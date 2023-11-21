#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll	q;
	cin>>q;
	ll tmp=sqrt(q);
	if(tmp*tmp==q) cout<<tmp;
	else if(tmp*tmp>q) cout<<tmp;
	else cout<<tmp+1;

}
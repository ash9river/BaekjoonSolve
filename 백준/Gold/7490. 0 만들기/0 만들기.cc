#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<char> picker;
vector<char> calc;
int n;
void pick(int toPick){
	if(toPick==0){
		string str="";
		string ansStr="";
		for(int i=0;i<picker.size();++i){
			str+=to_string(i+1);
			ansStr+=to_string(i+1);
			ansStr+=picker[i];
			if(picker[i]!=' '){
				str+=picker[i];
			}
		}
		str+=to_string(picker.size()+1);
		ansStr+=to_string(picker.size()+1);
		vector<int> findOperator;
		for(int i=0;i<str.size();++i){
			if(str[i]=='+'||str[i]=='-') findOperator.push_back(i);
		}
		if(!findOperator.empty()){
			vector<int> v;
			string tmp="";
			for(int i=0;i<findOperator[0];++i){
				tmp+=str[i];
			}
			v.push_back(stoi(tmp));
			for(int i=1;i<findOperator.size();++i){
				string tmptmp="";
				for(int j=findOperator[i-1]+1;j<findOperator[i];++j){
					tmptmp+=str[j];
				}
				int flag=1;
				if(str[findOperator[i-1]]=='-'){
					flag=-1;
				}
				v.push_back(flag*stoi(tmptmp));
			}
			tmp="";
			for(int i=findOperator[findOperator.size()-1]+1;i<str.size();++i){
				tmp+=str[i];
			}
			int flag=1;
			if(str[findOperator[findOperator.size()-1]]=='-') flag=-1;
			v.push_back(flag*stoi(tmp));
			int ans=0;
			for(int i=0;i<v.size();++i){
				ans+=v[i];
			}
			if(ans==0){
				cout<<ansStr<<"\n";
			}
		}
		return;
	}
	picker.push_back(' ');
	pick(toPick-1);
	picker.pop_back();
	picker.push_back('+');
	pick(toPick-1);
	picker.pop_back();
	picker.push_back('-');
	pick(toPick-1);
	picker.pop_back();
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t-->0){
		cin>>n;
		pick(n-1);
		cout<<"\n";
	}
}
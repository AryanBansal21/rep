#include<bits/stdc++.h>
using namespace std;

bool isterminal(char c)
{
	return (c>='a' && c<='z');
}

bool parse(int i,string in,string &out,map<char,vector<string>>&mp){
	int n=out.size();
	if(i==n){
		bool pos=1;
		for(int j=i;j<in.size();j++){
			if(isterminal(in[j])){
				pos=0;
				break;
			}
		}
		return pos;
	}
	
	if(isterminal(in[i])){
		if(in[i]!=out[i]) return 0;
		return parse(i+1,in,out,mp);
	}
	string tmp="";
	for(int j=0;j<i;j++) tmp+=in[j];
	for(auto x:mp[in[i]]){
		string newIn=tmp+x;
		for(int j=i+1;j<in.size();j++) newIn+=in[j];
		if(newIn[i]!=out[i]) continue;
		if(parse(i+1,newIn,out,mp)) return 1;
	}
	return 0;
}
int main(){
	map<char,vector<string>>mp;
	mp['S'].push_ack("aSbS");
	mp['S'].push_back("bSaS");
	mp['S'].push_back("");
	string out;
	cin>>out;
	if(parse(0,"S",out,mp)) cout<<"Successfully parsed"<<"\n";
	else cout<<"Unsuccessful"<<"\n";
} 

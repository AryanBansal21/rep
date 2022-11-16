#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<vector<int> >adj(n+1),par(n+1),den(n+1);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		par[v].push_back(u);
	}
	vector<int>full;
	for(int i=1;i<=n;i++) full.push_back(i);
	den[1]={1};
	for(int i=2;i<=n;i++) den[i]=full;
	for(int i=2;i<=n;i++){
		map<int,int>mp;
		int sz=par[i].size();
		for(int j:par[i]) for(int x:den[j]) mp[x]++;
		den[i].clear();
		den[i].push_back(i);
		for(auto j:mp) if(j.second==sz) den[i].push_back(j.first);
	}
	for(int i=1;i<=n;i++){
		cout<<i<<" ";
		sort(den[i].begin(),den[i].end());
		for(int j:den[i]) cout<<j<<" ";
		cout<<"\n";
	}
	return 0;
}

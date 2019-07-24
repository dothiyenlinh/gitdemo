#include<bits/stdc++.h>
using namespace std;
vector <int> v[100001];
void DFS(int u);
vector <int> path;

int vis[100001];
int main()
{
	int n;
	int k;
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		int m, x;
		cin>>m;
		for(int j=0; j<m; j++)
		{
			cin>>x;
			v[i].push_back(x);
		}
	}
	DFS(k);
	cout<<path.size()<<endl;
	
	sort(path.begin(),path.end());
	
	for(int i=0; i<path.size(); i++)
	{
		cout<<path[i]<<" ";
	}
}

void DFS(int u)
{
	vis[u]=1;
	path.push_back(u);
	
	for(int i=0; i<v[u].size(); i++)
	{
		if(!vis[v[u][i]])
		{
			DFS(v[u][i]);
		}
	}
}

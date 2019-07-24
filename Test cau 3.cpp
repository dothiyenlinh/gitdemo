#include<bits/stdc++.h>
using namespace std;
void DFS(int u);
int vis[1000];
vector<int> v[1001];
int main(){
	freopen("inp.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m,x;
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>x;
			v[i].push_back(x);
		}
	}
	int matrix[n+1][n+1];
	memset(matrix,0,sizeof matrix);
	bool ktCanhSS=0;
	for(int i=1;i<=n;i++){	
		for(int j=0;j<v[i].size();j++){
			if(matrix[i][v[i][j]])
				ktCanhSS=1;
			matrix[i][v[i][j]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<matrix[i][j]<<' ';
		cout<<endl;
	}
	bool ktDoiXung=true;
	bool ktVanhKhuyen=false;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j&&matrix[i][j]==1)
				ktVanhKhuyen=true;
			if(matrix[i][j]!=matrix[j][i]){
				ktDoiXung=false;
			}
		}
	}
	cout<<endl;
	if(ktVanhKhuyen&&ktCanhSS){
		cout<<"Do thi la da do thi ";
	}else{
		cout<<"Do thi la don do thi ";
	}
	if(ktDoiXung){
		cout<<"vo huong "<<endl;
	}else{
		cout<<"co huong "<<endl;
	}
	
	memset(vis,0,sizeof vis);
	DFS(1);
//	for(int i=1;i<=n;i++){
//		if(!vis[i])
//			DFS(i);
//	}
	bool ktTinhLienThong=true;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			ktTinhLienThong=false;
	if(ktTinhLienThong){
		cout<<"Do thi lien thong"<<endl;
	}else{
		cout<<"Do thi khong lien thong"<<endl;
	}
}
void DFS(int u){
	cout<<u<<" -> ";
	vis[u]=true;
	for(int i=0;i<v[u].size();i++)
		if(!vis[v[u][i]])
			DFS(v[u][i]);
}

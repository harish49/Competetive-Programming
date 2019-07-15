#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int visited[100];
vector<int>adj[100];
void dfs(int x){
	if(visited[x]==0){
		cout<<x<<' ';
		visited[x]=1;
	}

		for(auto i : adj ){
			for(int j = 0 ; j <i.size() ; j++ ){
				if(!visited[i[j]])
					dfs(i[j]);
			}
		}
return ;
}
int main()
{
	long int n;
	long int edges,x,y;
	cin >> n >> edges;
	for(int i = 0 ; i < edges ; i++ )
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 0 ; i < n ; i++ )
	{
		for(int j = 0 ; j < adj[i].size() ; j ++ )
		{
			cout<<adj[i][j]<<' ';
		}
		cout<<'\n';
	}
	dfs(0);
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int visited[100];
vector<int>adj[100];

vector<int> connectedcomponents(int i,vector<int> & x){
	
		x.push_back(i);
		visited[i]=1;
	
			for(int j = 0 ; j <adj[i].size() ; j++ ){
				if(!visited[adj[i][j]])
					connectedcomponents(adj[i][j],x);
			}
	return x;

}
using namespace std;
int main()
{
	int n,edges,x,y;
	cin >> n >> edges;
	for(int i = 0 ; i < edges ; i++ ){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(visited[i]==0)
		{
			vector<int>v;
			connectedcomponents(i,v);
			for(auto x : v){
				cout<<x<<' ';
			}
			cout<<'\n';
			v.clear();
		}
	}
}

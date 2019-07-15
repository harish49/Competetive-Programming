#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
int visited[100];
int *path=new int[100]{0};
int *parent = new int[100]{-1};

void bfs(int start,int n)
{
	queue<int>que;
	visited[start]=1;
	que.push(start);
	cout<<"BFS \n";
	while(!que.empty())
	{
		int node=que.front();
		que.pop();
		cout<<node << ' ';
		for(int i = 0 ; i < adj[node].size() ; i++ )
		{
			if(!visited[adj[node][i]])
			{
				que.push(adj[node][i]);
				visited[adj[node][i]]=1;
				path[adj[node][i]]=path[node]+1;
				parent[adj[node][i]]=node;
			}
		}
	}
	
	cout<<'\n';
	cout<<"Path "<<'\n';
	for(int i = 0 ; i<=n ;i ++ ){
		cout<<path[i]<<' ';
	}
	
	cout<<'\n';
	
	cout<<"Parent"<<'\n';
	for(int i = 0 ; i<=n ;i ++ ){
		cout<<parent[i]<<' ';
	}
}

void printpath(int s,int d)
{
	cout<<"\n"<<"Path[D,S]:"<<"\n";
	int temp=d;
	while(parent[temp]!=-1){
		cout<<temp<<"->";
		temp=parent[temp];
	}
}
int main()
{
	
	int n,edges,x,y;
	cin >> n >> edges;
	for(int i = 0 ; i <edges ; i++ )
	{
		cin >> x >> y;
		adj[x].push_back(y);
	}
	int start;
	cin >> start;
	bfs(start,n);
	printpath(1,5); // Source, Dest
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long int a[100][100],visited[100][100];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dfs(int i,int j,int m, int n)
{
	
	visited[i][j]=1;
	for(int x = 0 ; x < 8; x++)
	{
		int r = i+dx[x];
		int c = j+dy[x];
		if(r>=0 && r<m && c>=0 && c<n && a[r][c]==1 && visited[r][c]==0)
			return dfs(r,c,m,n)+1;
	}

}
int main()
{
	long int n,m;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++ )
		for(int j = 0 ; j < m ; j ++  )
			cin >> a[i][j];
	
	int ans=0;
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < m ; j ++ ){
			if(a[i][j]==1 && visited[i][j]==0)
			{
				int k =dfs(i,j,n,m);
				ans=max(ans,k);			
			}
		}
	}
	cout<<ans;
}


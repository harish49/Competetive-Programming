#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int grid[50][50];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool checkmatrix(int n)
{
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j < n ; j++ ){
			if(grid[i][j]<0){
				return false;
			}
		}
	}
	return true;
}
bool isvalid(int x,int y,int n)
{
	return (x>=0 && x<n && y>=0 && y<n );
}
int minpass(int n)
{
	int passes=0;
	queue<pair<int,int>>orig,curr;
	for(int i = 0 ; i < n ; i++ )
	{
		for(int j = 0 ;j < n ; j ++ ){
			if(grid[i][j]>0){
				orig.push({i,j});
			}
		}
	}
	while(!orig.empty())
	{
		while(!orig.empty())
		{
			curr.push(orig.front());
			orig.pop();
		}
		while(!curr.empty())
		{
			int x = curr.front().first;
			int y = curr.front().second;
			curr.pop();
			for(int i = 0 ; i < 4 ; i++ )
			{
				if(isvalid(x+dx[i],y+dy[i],n) && grid[x+dx[i]][y+dy[i]]<0)
				{
						grid[x+dx[i]][y+dy[i]]*=-1;
						orig.push({x+dx[i],y+dy[i]});
				}
			}
		}
		passes++;
		if(checkmatrix(n)){
		return passes;
	}
	}
		
}

int main()
{
	long int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++ )
	{
		for(int j = 0 ; j < n ; j++ )
		{
			cin >> grid[i][j];
		}
	}
	if(checkmatrix(n)){
		cout<<0;
	}
	else{
		cout<<minpass(n);
	}
	cout<<'\n';
	for(int i = 0; i < n ; i++ ){
		for(int j = 0 ; j < n  ;j ++){
			cout<< grid[i][j]<<" ";
		}
		cout<<"\n";
	}
}

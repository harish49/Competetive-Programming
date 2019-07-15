#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[100][100];
vector<int>path;
int mincostpath(int sx,int sy,int dx,int dy,int n)
{
	
	if(sx<0 ||sx>=n || sy<0||sy>=n)
	{
		return INT_MAX;
	}
	else if(sx==dx && sy==dy)
	{
		return a[sx][sy];
	}
	path.push_back(a[sx][sy]);
	return a[sx][sy]+min(mincostpath(sx+1,sy,dx,dy,n),mincostpath(sx,sy+1,dx,dy,n));
	path.pop_back();
}
int main()
{
	int n,i,j,s_x,s_y,d_x,d_y;
	cin >> n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin >> a[i][j];
		}
	}
	cin >> s_x >> s_y >> d_x >> d_y;
	cout<<mincostpath(s_x,s_y,d_x,d_y,n);
	for(i=0;i<path.size();i++)
	{
		cout<<path[i]<<' ';
	}
}

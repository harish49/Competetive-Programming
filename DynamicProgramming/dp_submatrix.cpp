#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int r,c,mat[20][20],ans=INT_MIN;

int largesubmat(int r,int c)
{
	int ans;
	if(r<0 || c<0)
	{
		return 0;
	}
	if(mat[r][c]==1)
	{
		ans=1+min(largesubmat(r-1,c),min(largesubmat(r,c-1),largesubmat(r-1,c-1)));
	}
	else 
	{
		ans=min(largesubmat(r-1,c),min(largesubmat(r,c-1),largesubmat(r-1,c-1)));
	}
}
int main()
{
	int i,j;
	cin >> r >> c;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cin>>mat[i][j];
		}
	}
	cout<<largesubmat(r-1,c-1);
}

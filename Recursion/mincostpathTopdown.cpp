#include<iostream>
#include<bits/stdc++.h>
int a[1000][1000];
using namespace std;
int solve(int r,int c,int n){
	int ans;
	if(r<0 || r>=n || c<0 || c>=n){
		return INT_MAX;
	}		
	if(r==n-1 && c==n-1){
		return a[r][c];
	}
cout<<ans<<' ';
	ans=a[r][c]+solve(r,c+1,n);
	
	
	return ans;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++ ){
		for(int j = 0 ; j< n;j++){
			cin >> a[i][j];
		}
	}
	cout<<solve(0,0,n);
}

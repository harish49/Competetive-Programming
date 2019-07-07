#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void subset(int *a ,int n)
{
	if(i==n)
	{
		return ;
	}
	for(int i = 0 ; i < n ; i ++ )
	{
		cout<<a[i]<<' ';
		subset(a,i+1);
	}
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> a[i];
	}
	subset(a,n);
}

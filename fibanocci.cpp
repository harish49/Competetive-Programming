#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int f[1000000];
int fib(int n)
{
	if(f[n]==-1)
	{
		if(n<=1)
		{
			f[n]=n;
		}
		else
		{
		f[n]=fib(n-1)+fib(n-2);
		}
	}
	return f[n];
}
int main()
{
	long int n;
	
	cin >> n;
	for(int i = 0 ; i <= n ; i++ )
	{
		f[i]=-1;
	}
	cout<<fib(n);
}

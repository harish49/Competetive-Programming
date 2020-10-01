#include<bits/stdc++.h>
using namespace std;
int main()
{
	long int n;
	cin >> n;
	long int a[n];
	for(int i = 0 ; i < n ; i ++ )
	{
		cin >> a[i];
	}
	for(int i = 0 ; i < 1<<n ; i ++ )
	{
		for(int j = 0 ; j<n ; j++ )
		{
			if(i&(1<<j)){
				cout<<a[j]<<' ';
			}
		}
		cout<<'\n';
	}
}

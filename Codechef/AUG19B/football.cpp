#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int goals[n],fouls[n];
		for(register int i = 0 ; i < n ; i ++ )
		{
			cin >> goals[i];
		}
		for(register int i = 0 ; i < n ; i ++ )
		{
			cin >> fouls[i];
		}
		int sum=0;
		for(int i = 0 ; i < n ; i ++ )
		{
			sum=max(sum,(((goals[i]*20)-(fouls[i]*10)))>0?((goals[i]*20)-(fouls[i]*10)):0);
		}
		cout<<sum<<'\n';
	}
}

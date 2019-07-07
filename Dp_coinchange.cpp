#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mincoin(int *coins,int sum,int n)
{
	if(sum==0){
		return 1;
	}
	if(sum<0){
		return 99999999;
	}
	int ans=0,final=9999999;
	
	for(int i =0 ; i<n; i ++ )
	{
		if(sum-coins[i]>=0){
		
		ans+=mincoin(coins,sum-coins[i],n);
		final=min(final,ans);
	}
	}
	cout<<final<< ' ';
	return ans;	
}
int main()
{
	int n,a,b,c;
	cin >> n ;
	int coins[]={2,3,4};
	cout<<mincoin(coins,n,3);
}

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
		int a[n],prefix[n],suffix[n];
		for(int i = 0 ; i < n ; i++ )
		{
			cin>>a[i];
			if(i=0){
				prefix[i]=a[i];
			}
			else{
				prefix[i]=prefix[i-1] xor a[i];
			}
			
		}
		suffix[n-1]=a[n-1];
		for(int i = n-2; i>=0 ; i--)
		{
			suffix[i]=suffix[i+1] xor a[i];
		}
		long int c=0;
		for(int i = 0 ; i < n ; i ++ ){
			if(prefix[i]==0){
				c+=i;
			}
		}
		for(int i = 1 ; i < n ; i++)
		{
			if(suffix[i]==0){
				c+=n-i;
			}
		}
		cout<<c;
		
	}
}

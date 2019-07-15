#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,queries;
	cin >> n >> queries;
	int a[n];
	int *segtree = new int[2*n];
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> a[i];
	}
	for(int i = 0 ; i < n ; i++)
	{
		segtree[n+i]=a[i];
	}
	for(int i = n-1 ; i >= 1 ; i-- )
	{
		segtree[i]=min(segtree[2*i],segtree[2*i+1]);
	}
	cout<<'\n';
	for(int i = 0 ; i < 2*n ; i++ )
	{
		cout<<segtree[i]<<' ';
	}
	int x,y;
	
	char type;
	// 1 x y - minimum in range [x,y] 1 - based querying
	// 2 x y - update a[x] = y    0 based querying
	
	while(queries--){
		
		cin >> type >> x >> y;
		if(type=='q')
		{
			x--;
			int  l = x+n;
			int  r = y+n;
			int mini=INT_MAX;
			while(l<r)
			{
				if(l%2==1){
					mini=min(mini,segtree[l]);
					l++;
				}
				if(r%2==1){
					r--;
					mini=min(mini,segtree[r]);
				}
				l>>=1;
				r>>=1;
			}
			cout<<mini<<'\n';
		}
		else
		{
			x--;
			x+=n;
			segtree[x]=y;
			while(x>1)
			{
				x>>=1;
				segtree[x]=min(segtree[2*x],segtree[2*x+1]);
			}	
		}
	}
}

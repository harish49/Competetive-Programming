#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mp[100010]={0};
void buildtree(int *a,int *segtree,int index,int s, int e)
{
	if(s>e)
	{
		return;
	}
	if(s==e)
	{
		if(mp[a[s]]==0)
		{
			mp[a[s]]=1;
			segtree[index]=1;
		}
		else
		{
			segtree[index]=0;
		}
		return;
	}
	int mid=(s+e)/2;
	buildtree(a,segtree,2*index,s,mid);
	buildtree(a,segtree,2*index+1,mid+1,e);
	segtree[index]=segtree[2*index]+segtree[2*index+1];
}
void update(int *segtree,int index,int s, int e ,int node, int val)
{
	if(node<s||node>e)
	{
		return;
	}
	if(s==e)
	{
		if(mp[val]==1)
		{
			segtree[index]=0;
		}
		else
		{
			segtree[index]=1;
			mp[val]=1;
		}
		return;
	}
	int mid=(s+e)/2;
	update(segtree,2*index,s,mid,node,val);
	update(segtree,2*index+1,mid+1,e,node,val);
	segtree[index]=segtree[2*index]+segtree[2*index]+1;
	return;
}
int query(int *segtree,int index,int s, int e ,int l ,int r)
{
	if(l>e || r<s)
	{
		return 0;
	}
	if(s>=l && e<=r)
	{
		return segtree[index];
	}
	int mid=(s+e)/2;
	int left=query(segtree,2*index,s,mid,l,r);
	int right=query(segtree,2*index+1,mid+1,e,l,r);
	return left+right;
}
int main()
{
	int n,q,type,l,r;
	cin >> n >> q;
	int a[n+1];
	register int i;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int segtree[4*n+1];
	buildtree(a,segtree,1,0,n-1);
	while(q--)
	{
		cin >> type >> l >> r;
		if(type==0)
		{
			update(segtree,1,1,n,l,r);
		}
		else
		{
			cout<<query(segtree,1,1,n,l,r)<<'\n';
		}
	}
}

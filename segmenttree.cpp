/*
Author : Vemula Harish
Topic : Segment Tree
Problem : Range minium query
Paradigm : Divide and Conquer
Language : C++14
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long int int_max=1e9;

void build(int *a, int *tree, int index ,int s, int e)
{
	//Bottom up approach
	
	if(s>e)
	{
		return;
	}
	
	//Base case - fill the nodes with leaf nodes
	if(s==e)
	{
		tree[index]=a[s];
		return;
	}
	
	int mid=(s+e)/2;
	build(a,tree,2*index,s,mid);
	build(a,tree,2*index+1,mid+1,e);
	
	int lchild=tree[2*index];
	int rchild=tree[2*index+1];
	
	tree[index]=min(lchild,rchild);
} 

int query(int *tree, int index ,int s,int e ,int qs , int qe)
{
	//No overlap
	if(qs>e||qe<s)
	{
		return int_max;
	}
	
	//Complete overlap return the node value
	if(s>=qs && e<=qe)
	{
		return tree[index];
	}
	
	//Partial overlap
	int mid=(s+e)/2;
	int left=query(tree,2*index,s,mid,qs,qe);
	int right=query(tree,2*index+1,mid+1,e,qs,qe);
	
	return min(left,right);
	
}
void update(int *tree , int index , int s ,int e , int node , int val)
{
	if(node<s||node>e)
	{
		return;
	}
	if(s==e)
	{
		tree[index]=val;
		return;
	}
	int mid=(s+e)/2;
	update(tree,2*index,s,mid,node,val);
	update(tree,2*index+1,mid+1,e,node,val);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}
int main()
{
	int n,q,type,l,r;
	cin >> n >> q;
	int a[n];
	
	for(register int i = 0 ; i < n ; i++)
	{
		cin >> a[i];
	}
	// Building the segment tree
	int *segmentTree = new int[(4*n)+1];
	int index=1;
	int s=0;
	int e=n-1;
	build(a,segmentTree,index,s,e);
	
	// Range query
	while(q--)
	{
		cin >> type >> l >> r;
		if(type==1)
		{
			cout<<query(segmentTree,1,0,n-1,l-1,r-1)<<'\n';
		}
		else
		{
			update(segmentTree,1,0,n-1,l-1,r);
		}
	}
}

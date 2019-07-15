#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void heapify(long int a[],long int n,long int i)
{
	long int root=i;
	long int left=(2*i)+1;
	long int right=(2*i)+2;
	if(left<n && a[left]>a[root])
	{
		root=left;
	}
	if(right<n && a[right]>a[root])
	{
		root=right;
	}
	if(root!=i)
	{
		swap(a[i],a[root]);
		heapify(a,n,root);
	}
}
void max_heap(long int a[],long int n)
{
	long int i;
	for(i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
	for(i=n-1;i>=0;i--)
	{
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}
int main()
{
	long int n,i;
	cin>>n;
	long int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	max_heap(a,n);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<' ';
	}
}

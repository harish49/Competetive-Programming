#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct data
{
	int pref;
	int suff;
	int ans;
	int sum;
	data()
	{
		pref=-99999;
		suff=-99999;
		ans=-99999;
		sum=-99999;
	}
};

data merge(data a ,data b)
{
	data parent;
	parent.sum=a.sum+b.sum;
	parent.pref=max(a.pref,a.sum+b.pref);
	parent.suff=max(b.suff,b.sum+a.suff);
	parent.ans=max({a.ans,b.ans,a.sum+b.sum,a.suff+b.pref});
	return parent;
}
void build(data segtree[],int a[],int index,int low,int high)
{
	if(low>high){
		return;
	}
	if(low==high)
	{
		segtree[index].ans=a[low];
		segtree[index].suff=a[low];
		segtree[index].pref=a[low];
		segtree[index].sum=a[low];
		return;
	}
	int mid=(low+high)/2;
	build(segtree,a,2*index,low,mid);
	build(segtree,a,2*index+1,mid+1,high);
	segtree[index]=merge(segtree[2*index],segtree[2*index+1]);
}
data sum(data segtree[],int index,int low,int high,int qs,int qe)
{
	if(qs>high||qe<low){
		data g;
		return g;
	}
	if(qs<=low && qe>=high)
	{
		return segtree[index];
	}
	int mid=(low+high)/2;
	return merge(sum(segtree,2*index,low,mid,qs,qe),sum(segtree,2*index+1,mid+1,high,qs,qe));
}
void update(data segtree[],int index,int low,int high,int pos,int val)
{
	if(pos<low || pos>high){
		return;
	}
	if(low==high)
	{
		segtree[index].ans=segtree[index].suff=segtree[index].pref=segtree[index].sum=val;
		return;
	}
	int mid=(low+high)/2;
	update(segtree,2*index,low,mid,pos,val);
	update(segtree,2*index+1,mid+1,high,pos,val);
	segtree[index]=merge(segtree[2*index],segtree[2*index+1]);
	return;
}
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
	int n,q;
	cin >> n >> q;
	int a[n];
	for(int i = 0 ; i< n ; i++ )
	{
		cin >> a[i];
	}
	data segtree[4*n];
	build(segtree,a,1,0,n-1);
	int l,r,type;
	while(q--)
	{
		cin >> type >> l >> r;
		if(type==1){
			cout<<sum(segtree,1,0,n-1,l-1,r-1).ans<<'\n';
		}
		else{
			update(segtree,1,0,n-1,l-1,r);
		}
	}
    }
}

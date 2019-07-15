#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long int N,i,j,query;
	cin>>N;
	long int a[N+1];
	long int block_size=sqrt(N);
	vector<pair<long int,pair<long int,long int> > >v;
	for(i=1;i<=N;i++)
	{
		cin>>a[i];
	}
	cin>>query;
	long long int sum=0;
	for(i=1;i<=N-(N%block_size);i++)
	{
		sum+=a[i];
		if(i%block_size==0)
		{
			v.push_back(make_pair(sum,make_pair(i-block_size+1,i)));
			sum=0;
		}
	}
	if(N%block_size!=0)
	{
	j=i;
	sum=0;
	while(i<=N)
	{
		sum+=a[i];
		i++;
	}
	v.push_back(make_pair(sum,make_pair(j,N)));
    }
    long int l,r,x,l_ind,r_ind;
    while(query--)
    {
    	sum=0;
    	cin>>x;
    	if(x==1)
    	{
    	cin>>l>>r;
    	if(l==r)
    	{
    		cout<<a[l];
		}
		else
		{
			if(l%block_size==0 && r%block_size!=0)
			{
				l_ind=(l/block_size)-1;
				r_ind=(r/block_size);
			}
			else if(l%block_size!=0 && r%block_size==0)
			{
			l_ind=l/block_size;
			r_ind=(r/block_size)-1;
		    }
		    else if(l%block_size==0 && r%block_size==0)
		    {
		    	l_ind=(l/block_size)-1;
				r_ind=(r/block_size)-1;
			}
			else
			{
				l_ind=(l/block_size);
				r_ind=(r/block_size);
			}
			if(l_ind==r_ind)
			{
				for(i=l;i<=r;i++)
				{
					sum+=a[i];
				}
				cout<<sum;
			}
			else
			{
				for(i=l_ind;i<=r_ind;i++)
				{
					sum+=v[i].first;
				}
	 			l_ind=(l_ind*block_size)+1;
	 			while(l_ind<l)
	 			{
	 				sum-=a[l_ind];
	 				l_ind++;
				}
				r_ind=min(N,((r_ind+1)*block_size));
				while(r_ind>r)
				{
					sum-=a[r_ind];
					r_ind--;
				}
				cout<<sum;
			}
		}
		cout<<'\n';
	}
	else
	{
		if(l%block_size==0)
		{
			v[(l/block_size)-1].first=v[(l/block_size)-1].first+r-a[l];
		}
		else
		{
			v[(l/block_size)].first=v[(l/block_size)].first+r-a[l];
		}
	}
	}
}

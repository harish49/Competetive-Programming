#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void calculateZ(string s,int Z[])
{
	int i,j,l=0,r=0,k;
	for(i=1;i<s.size();i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<s.size() &&s[r-l]==s[r])
			{
				r++;
			}
			Z[i]=r-l;
			r--;
		}
		else
		{
			k=i-l;
			if(Z[k]<r-i+1)
			{
				Z[i]=Z[k];
			}
			else
			{
				l=i;
				while(r<s.size() &&s[r-l]==s[r])
				{
					r++;
				}
				Z[i]=r-l;
				r--;
			}
		}
	}
}
int main()
{
	int i,freq=0;
	string main_str,pattern;
	cin>>main_str>>pattern;
	string res=pattern+"$"+main_str;
	int size=res.size();
	int Z[size];
  	calculateZ(res,Z);
  	for(i=0;i<size;i++)
  	{
  		if(Z[i]==pattern.size())
  		{
  			freq++;
		}
	}
	cout<<freq<<'\n';
}

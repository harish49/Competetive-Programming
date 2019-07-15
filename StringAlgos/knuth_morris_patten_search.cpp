#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void calculatelps(string s,int size,int lps[])
{
	int i,len=0;
	lps[0]=0;
	i=1;
 	while(i<size)
 	{
 		if(s[i]==s[len])
 		{
 			len++;
 			lps[i]=len;
 			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
int main()
{
	register int i,j;
	string main_str,pattern;
	cin>>main_str>>pattern;
	int l=main_str.size();
	int p=pattern.size();
	int lps[p],freq=0;
	calculatelps(pattern,p,lps);
	i=0;
	j=0;
	while(i<l)
	{
		if(pattern[j]==main_str[i])
		{
			i++;
			j++;
		}
		if(j==p)
		{
			freq++;
			j=lps[j-1];
		}
		else if(i<l && pattern[j]!=main_str[i])
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	cout<<freq;
}


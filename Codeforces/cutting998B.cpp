#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long int n,B;
	cin >> n >> B;
	long int a[n];
	register int i ;
	for(int i =0 ; i < n ; i++ )
	{
		cin >> a[i];
	}	
	int odd=0,eve=0;
	if(n%2==1)
	{
		cout<<"0";
		return 0;
	}
	long int cut=0;
	vector<int>v;
	for(int i = 0 ; i < n ; i++ )
	{
		if(odd==eve && odd>0 && eve>0){
			v.push_back(abs(a[i]-a[i-1]));
			odd=0;
			eve=0;
		}
		 if(a[i]%2==0){
			eve++;
		}
		else{
			odd++;
		}
	}
	sort(v.begin(),v.end());
	int sum=0;
	for(int i = 0 ; i < v.size() ; i ++ )
	{
		sum=sum+v[i];
		if(sum<=B){
			cut++;
		}
		else{
			break;
		}
	}
	if(cut==0){
		cout<<"0";
	}
	else
	{
		cout<<cut;
	}
}

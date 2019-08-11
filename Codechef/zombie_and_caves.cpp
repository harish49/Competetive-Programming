#include<iostream>
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false)
#define int long long
using namespace std;
int32_t main()
{
	fast;
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,x,left,right;
		cin >> n;
		vector<int>radio,res;
		radio.assign(n+1,0);
		res.assign(n+1,0);
		int z[n],j;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> x;
			left=max(1LL,i-x);
			right=min(n,i+x);
			radio[left]++;
			if(right+1<=n)
			radio[right+1]--;
		}
		res[0]+=radio[1];
		for(int i = 2 ; i <radio.size() ; i++)
		{
			radio[i]+=radio[i-1];
			res[i-1]+=radio[i];
		}
		sort(res.begin(),res.end());
		for(int i = 0 ; i<n;i++)
		{
			cin>>z[i];
		}
		sort(z,z+n);
		
		bool ans=true;
		for(int i = 0 ; i<n; i++)
		{
			if(z[i]!=res[i+1]){
				ans=false;
			}
		}
		if(ans==true){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
		cout<<"\n";
	}
}

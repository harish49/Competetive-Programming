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
	int t,c=0;
	cin >> t;
	string s;
	vector<int>v;
	while(t--){
		cin >> s;
		c=0;
		bool win=true;
		for(int i = 0 ; i < s.size() ; i++ )
		{
			if(s[i]=='1'){
				c++;
			}
			else{
				if(c>0)
				v.push_back(c);
				c=0;
			}
		}
		if(c!=0)
		{
			v.push_back(c);
		}
		int odd=0;
		for(auto x : v)
		{
			if(x%2==1){
				odd++;
			}
		}
		if(odd%2==0){
			cout<<"LOSE";
		}
		else{
			cout<<"WIN";
		}
		cout<<"\n";
		v.clear();
	}
}

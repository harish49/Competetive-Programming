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
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		if((n/k)!=k && (n/k)%k!=0){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
		cout<<'\n';
	}
return 0;
}

#include<bits/stdc++.h> 
using namespace std; 
int power(int x, int y, int p) 
{ 
	int res = 1;	  

	x = x % p; 
	
	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res*x) % p; 
	y = y>>1; 
		x = (x*x) % p; 
	} 
	return res; 
} 

// Returns n^(-1) mod p 
int modInverse(int n, int p) 
{ 
	return power(n, p-2, p); 
} 

 
int nCrModPFermat(int n, int r, int p) 
{ 
if (r==0) 
	return 1; 

	int fac[n+1]; 
	fac[0] = 1; 
	for (int i=1 ; i<=n; i++) 
		fac[i] = fac[i-1]*i%p; 

	return (fac[n]* modInverse(fac[r], p) % p * 
			modInverse(fac[n-r], p) % p) % p; 
} 

int main() 
{
	int n,r,p;
	cin>>n>>r>>p; 
 	long long int ans = nCrModPFermat(n, r, p); 
	cout<<ans; 
} 


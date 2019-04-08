/*

--------------------------------------------- C++ TEMPLATE FOR COMPETETIVE PROGRAMMING----------------------------------------------------------
Author : Harish Vemula
Handle : harish49

*/

#include "iostream"
#include "algorithm"
#include "stack"
#include "queue"
#include "string"
#include "deque"
#include "list"
#include "map"
#include "set"
#include "vector"
#include "stdlib.h"
#include "functional"
#include "cmath"
#include "string"
#include "numeric"
#include "iterator"
#include "bitset"

using namespace std;

#define inp(x) scanf("%d",&x)
#define inpl(x) scanf("%ld",&x)
#define inpll(x) scanf("%lld",&x)
#define inpc(x) scanf("%c",&x)
#define inps(x) scanf("%s",x)
#define inpf(x) scanf("%f",&x)
#define inplf(x) scanf("%lf",&x)
#define rg register int
#define ld long int
#define lld long long int
#define usd unsigned long long int
#define mset(arr, val) memset(arr, val , sizeof(arr))
#define fr(i,val,size,it) for(register int i=val; i<size ; i+=it)
#define rfr(i,size,val,it) for(register int i=size-1; i>=val; i-=it)
#define all(container) container.begin(), container.end()
#define rall(cont) container.end(), container.begin()
#define each(it, s) for (auto it = s.begin(); it != s.end(); ++it)
#define mk make_pair
#define pb push_back
#define em emplace_back
#define inf (long long int)1e9
#define big INT_MAX
#define small INT_MIN
#define pi 3.1415926535897932384626433832795
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false)
typedef pair<int, int> p_ii;
typedef vector<int> v_i;
typedef vector<string> v_s;
typedef vector<pair<int , int> > vp_ii;
typedef vector< vector<int> > vvi;
typedef map<int,int> mp_ii;
typedef set<int> set_i;
typedef multiset<int> ms_i;

long int get_lcm(long int x,long int y)
{
lld lcm;
if (x>=y && x%y==0)
{
lcm=a;
}
else if(y>=x && y%x==0)
{
lcm=y;
}
else
{
lcm=x*y;
}
return lcm;
ld gcd=(a*b)/lcm;
}

long int get_gcd(long int x,long int y)
{
lld lcm;
if (x>=y && x%y==0)
{
lcm=a;
}
else if(y>=x && y%x==0)
{
lcm=y;
}
else
{
lcm=x*y;
}
lld gcd=(a*b)/lcm;
return gcd;
}
vector<int> stringtonum(string s)
{
vector<int>vect;
fr(i,0,s.size(),1)
{
vect.pb(s[i]-'0');
}
return vect; // return vector
}
int main()
{
fast;
cin.tie(0);
cout.tie(0);

                                        /* Some common practices to be followed */

/* Use scanf for faster input */

/* Use '\n' instead of endl */

/* Use register int for initialising loop counters eg: register int i,j; */

/* Use emplace_back for faster input in vector */

/* While declaring an array , first read the size and then initialise an array of size (eg : arr[size]), it will optimise the code memory */

/* For declaring an array of larger size such as greater than 10^6 elements, declare the array globally */

/* Initialisize the variables outside the loop , if they are to be read multiple times , it's a good practice
Example :

int n;
while(testcase--)
{
scanf("%d",&n);
}
*/

/* Use 1LL , in case of multiplying large numbers  Eg : long long int big = 1LL*241241*1241241; */

/* Use (1<<k) , for calculating 2 power k */

/* To calculate the number of digits use : floor(log(number))+1 , base=10 */

/* To take input with spaces  , use getline method : getline(cin, s); where s is a string */

/*------------------------------------------------------SOME FUNCTIONS--------------------------------------------------------------------*/

/* Convert string to an integer array 
vector<int>v;
string s;
inps(x);
v=stringtonum(x);
*/


/* 
lcm and gcd of two numbers with out functions 
inpl(a);
inpl(b);
ld lcm=get_lcm(a,b);
ld gcd=get_gcd(a,b);
*/
  
/*
For rounding up the division values :
lld q = (x + y - 1) / y;

For performing ceil operation :
lld q = (x / y) + (x % y != 0)

For performing floor operation :
lld q = (x / y) 
*/
 
}


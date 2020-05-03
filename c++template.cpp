/*
--------------------------------------------- C++ TEMPLATE FOR COMPETETIVE PROGRAMMING----------------------------------------------------------
Author : Harish Vemula
Handle : harish_49
*/

// #pragma GCC optimize "trapv" Uncomment when dealing with huge numbers
/*<----------PBDS---------->

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using order_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

order_set<datatype>oset;
Kth smallest : *oset.find_by_order(k-1); // 0 based index
No of elements less than k : oset.order_of_key(k);
Erase X : oset.erase(x)
<----------PBDS---------->*/
#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define pb(x) push_back(x)
#define gcd(a,b) __gcd(a,b)
#define all(v) v.begin(),v.end()
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int32_t main()
{
    /*  HEYY YOU !! You wanna be a coder , then stop using those  huge templates, maintain some shorter one like this .
        Trust me , you will be having an edge when compared with the people who use templates ............ HELLO PROGRAMMERS :) */
}




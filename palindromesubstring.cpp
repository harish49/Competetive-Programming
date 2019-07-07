#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int palindrome(int i ,int j , string s){

	if(i>=j){
		return 1;
	}
	if(s[i]!=s[j]){
		return 0;
	}
	return palindrome(i+1,j-1,s);
}
int main()
{
	string s;
	cin >> s;
	int ans=0;
	for(int i = 0 ; i < s.size() ; i++ ){
		for(int j = i ; j < s.size() ; j++){
			ans+=palindrome(i,j,s);
		}
	}
	cout<<ans;
}

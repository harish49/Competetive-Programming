#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Trie
{
	struct Trie*child[26];
	int freq[26];
	bool endword;
};
struct Trie*getnode()
{
	struct Trie*newnode=new Trie;
	for(int i = 0 ; i < 26 ; i++ )
	{
		newnode->child[i]=NULL;
		newnode->freq[i]=0;
	}
	newnode->endword=false;
	return newnode;
}
void insert(struct Trie*root , string s)
{
	struct Trie*temp=root;
	int index;
	for(int i = 0 ; i < s.size() ; i++ )
	{
		index=s[i]-'a';
		temp->freq[index]++;
		if(!temp->child[index])
		{
			temp->child[index]=getnode();
		}
		temp->endword=true;
		temp=temp->child[index];
	}
	temp->endword=true;
}
int search(struct Trie*root , string s)
{
	struct Trie*temp=root;
	int index,ans=0;
	for(int i = 0 ; i < s.size() ; i++ )
	{
		index=s[i]-'a';
	    if(!temp->child[index])
		{
		return 0;
		}
		ans=temp->freq[index];
		temp=temp->child[index];
	}
	return ans; 
}
int main()
{
	int n,q;
	string s;
	cin >> n >> q;
	struct Trie*root=getnode();
	while(n--)
	{
		cin >> s;
		insert(root,s);
	}
	while(q--)
	{
		cin >> s;
		cout<<search(root,s)<<'\n';
	}
}

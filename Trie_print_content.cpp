#include<bits/stdc++.h>
using namespace std;
struct Trie
{
	struct Trie*child[26];
	bool endword;
};
struct Trie*getnode()
{
	struct Trie*newnode=new Trie;
	for(int i = 0 ; i < 26 ; i++ )
	{
		newnode->child[i]=NULL;
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
		if(!temp->child[index])
		{
			temp->child[index]=getnode();
		}
		temp=temp->child[index];
	}
	temp->endword=true;
}
bool search(struct Trie*root , string s)
{
	struct Trie*temp=root;
	int index;
	for(int i = 0 ; i < s.size() ; i++ )
	{
		index=s[i]-'a';
		if(!temp->child[index])
		{
			return false;
		}
		temp=temp->child[index];
	}
	if(temp->endword==true && temp!=NULL)
	{
		return true;
	}
	return false;
}
bool isleaf(struct Trie*root)
{
	return root->endword!=false;
}
void printTrie(struct Trie * root ,char str[], int level)
{
	if(isleaf(root))
	{
		str[level]='\0';
		cout<<str<<'\n';
	}
	for(int i=0 ; i < 26 ; i++ )
	{
		if(root->child[i])
		{
		str[level]='a'+i;
		printTrie(root->child[i],str,level+1);
		}
	}
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
		if(search(root,s))
		{
			cout<<"YES"<<'\n';
		}
		else
		{
			cout<<"NO"<<'\n';
		}
	}
	char str[20];
	printTrie(root,str,0);
}

#include<iostream>
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
struct Trie *prefixsearch(struct Trie *root, string key) {
    struct Trie *temp=root;
    for(int i=0;i<key.size();i++) {
        int  index=key[i]-'a';
        if(!temp->child[index])
            return NULL;
        temp=temp->child[index];
    }
    return temp;
}

vector <char> res;
set <string > ans;

void prefixprint(struct Trie *root)
{
    if(root->endword)
	 {
        string s="";
        for(int i=0;i<res.size();i++)
            s+=res[i];
        ans.insert(s);
    }
    for(int i=0;i<26;i++) {
        if(root->child[i]!=NULL) {
           
            res.push_back((char)(i+97));
            prefixprint(root->child[i]);
        }
    }
    res.pop_back();
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
	int prefix_q;
	string prefix;
	cin >> prefix_q;
	struct Trie *temp;
	while(prefix_q--)
	{
	cin >> prefix;
	temp=prefixsearch(root,prefix);
	if(temp==NULL)
	{
		cout<<"No string with given prefix\n";
	}
	else
	{
	for(int i = 0 ; i < prefix.size() ; i ++ )
	{
		res.push_back(prefix[i]);
	}
	prefixprint(temp);
	res.clear();
	for(auto it = ans.begin()  ; it!=ans.end() ; ++it )
	{
		cout<<*it<<" ";
	}
	cout<<'\n';
	ans.clear();
	}
	}
}

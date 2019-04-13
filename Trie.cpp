#include <bits/stdc++.h> 
#include <unordered_map> 
using namespace std; 


struct trie 
{ 
	unordered_map<char,trie*>mp;

	int word_end=0; 
	
}; 

trie *getNode() 
{ 
	trie *new_node = new trie; 

	new_node->word_end = 0; 

	return new_node; 
} 
void insert(trie* &root, string key) 
{ 
     if(root == nullptr)
     {
         root=getNode();
     }
      trie *current = root;
	for (int i = 0 ; i < key.size() ; i++ )
	{
		if(current->mp.find(key[i])==current->mp.end())
		{
			current->mp[key[i]]=getNode();
		}
		current=current->mp[key[i]];
	}
	current->word_end++;
} 

bool search(trie *root, string key) 
{ 
	trie *current = root; 
	if(current==NULL)
	{
		return false;
	}
	for(int i = 0 ; i < key.size() ; i++ )
	{
		if(current->mp[key[i]])
		{
			current=current->mp[key[i]];
		}
		else
		{
			return false;
		}
	}
	if(current->word_end==0)
	{
	   return false;
	}
	return true;
} 
int occurence(trie *root, string key) 
{ 
	trie *current = root; 
	if(current==NULL)
	{
		return 0;
	}
	for(int i = 0 ; i < key.size() ; i++ )
	{
		if(current->mp[key[i]])
		{
			current=current->mp[key[i]];
		}
		else
		{
			return 0;
		}
	}
	return current->word_end;
} 

bool delete_trie(trie *root , string key)
{
	trie *current=root;
	if(current==nullptr)
	{
		return false;
	}
	for( int i = 0 ; i < key.size() ; i++ )
	{
		if(current->mp[key[i]])
		{
			current=current->mp[key[i]];
		}
		else
		{
			return false;
		}
	}
	current->word_end--;
	return true;
}
int main() 
{ 
	trie *root= nullptr;
	int n,query;
	cin>>n>>query;
	string s;
	while(n--)
	{
	 cin>>s;
	 insert(root ,s);
	}
	string x;
	int y;
	while(query--)
	{
	    cin>>y>>x;
	    if(y==1)
	    {
	        if(search(root,x))
	        {
	            cout<<x<<" "<<"FOUND";
	        }
	        else
	        {
	            cout<<"NOT FOUND";
	        }
	    }
	    else if(y==2)
	    {
	        if(delete_trie(root,x))
	        {
	            cout<<x<<" "<<"DELETED";
	        }
	        else
	        {
	            cout<<"NOT FOUND";
	        }
	    }
	    else if(y==3)
	    {
	        cout<<occurence(root,x);
	    }
	    cout<<'\n';
	}
	return 0; 
} 

